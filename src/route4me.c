
#include <json.h>
#include <curl/curl.h>
#include "../include/route4me.h"
#include <string.h>

struct http_resp
{
    char *memory;
    size_t size;
};

static char szEmptyResponse[] = "empty http response";
static char szParseError[] = "json parse error(s)\n";
static char szAPIError[] = "route4me api errors:";

static struct response_data current_response = {0};

struct response_data getCurrentResponse()
{
    return current_response;
}

static void setCurrentResponse(int error_code, const char* error_message, int error_strlen)
{
    current_response.m_err_code = error_code;
    current_response.m_err_msg = realloc(current_response.m_err_msg, strlen(error_message) + 1);
    strcpy(current_response.m_err_msg, error_message);
}

int getErrorCode()
{
    return current_response.m_err_code;
}

char* getErrorMessage()
{
    return current_response.m_err_msg;
}

char* getRawResponse()
{
    return current_response.m_raw_resp;
}

json_object* getJSONResponse()
{
    return current_response.m_json_resp;
}

static void cleanCurrentResponse()
{
    if (current_response.m_err_msg != NULL)
    {
        free(current_response.m_err_msg);
    }
    memset(&current_response, 0, sizeof(struct response_data));
}

static const char VEHICLES_SERVICE[] = "https://www.route4me.com/api/vehicles/view_vehicles.php";
static const char R4_API_HOST[] = "https://www.route4me.com/api.v4/optimization_problem.php";
static const char ROUTE_HOST[] = "https://www.route4me.com/api.v4/route.php";
static const char DUPLICATE_ROUTE[] = "https://www.route4me.com/actions/duplicate_route.php";
static const char SHARE_HOST[] = "https://www.route4me.com/actions/route/share_route.php";
static const char ADD_ROUTE_NOTES[] = "https://www.route4me.com/actions/addRouteNotes.php";
static const char ADDRESS_HOST[] = "https://www.route4me.com/api.v4/address.php";
static const char GPS_HOST[] = "https://www.route4me.com/track/set.php";
static const char ACTIVITIES_HOST[] = "https://www.route4me.com/api/get_activities.php";
static const char USERS_HOST[] = "https://www.route4me.com/api/member/view_users.php";
static const char AUTHENTICATION_HOST[] = "https://www.route4me.com/actions/authenticate.php";
static const char TRACKING_HOST[] = "https://route4me.com/api.v4/status.php";
static const char LOCATION_HOST[] = "https://www.route4me.com/api/track/get_device_location.php";
static const char GEOCODER[] = "https://www.route4me.com/api/geocoder.php";
static const char STREETS_HOST[] = "https://rapid.route4me.com/street_data/";
static const char AVOIDANCE_HOST[] = "https://www.route4me.com/api.v4/avoidance.php";
static const char ORDER_HOST[] = "https://www.route4me.com/api.v4/order.php";
static const char CONFIG_SERVICE[] = "https://route4me.com/api.v4/configuration-settings.php";
static const char PREVIEW_SERVICE[] = "https://www.route4me.com/actions/upload/csv-xls-preview.php";
static const char UPLOAD_SERVICE[] = "https://www.route4me.com/actions/upload/upload.php";
static const char UPLOAD_GEOCODING[] = "https://www.route4me.com/actions/upload/csv-xls-geocode.php";
static const char VALIDATE_SESSION[] = "https://www.route4me.com/datafeed/session/validate_session.php";
static const char TERRITORY_HOST[] = "https://route4me.com/api.v4/territory.php";
static const char ADDRESS_BOOK_HOST[] = "https://www.route4me.com/api.v4/address_book.php";

// TODO: Revise api key length
static char m_key[100];
static void* curl;
static int verbose;
static struct curl_httppost *formpost;

void init(char* szKey, int nVerbose)
{
    strcpy(m_key, szKey);
    verbose = nVerbose;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
}

void cleanUp()
{
    if (curl)
        curl_easy_cleanup(curl);
    if (formpost)
        curl_formfree(formpost);
    curl_global_cleanup();
    cleanCurrentResponse();
}

static void make_arg(char *url, json_object* params)
{
        int first = 1;

        json_object_object_foreach(params, key, val)
        {
            if (first) {
                strcat(url, "?");
                first = 0;
            }
            else
                strcat(url, "&");
            strcat(url, key);
            strcat(url,"=");

            char* json = strdup(json_object_to_json_string(val));

            if (json[0] == '"')
            {
                json[strlen(json) - 1] = '\0';
                ++json;
            }
            strcat(url, json);
        }
}

static size_t read_http_resp(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    struct http_resp *mem = (struct http_resp *)userp;
    mem->memory = (char*) realloc(mem->memory, mem->size + realsize + 1);
    if(mem->memory == NULL) return 0;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

static int request(enum ReqType method, void *curl, char *url, json_object *props, char* payload)
{
    long http_code = 0L;
    struct http_resp chunk;
    chunk.memory = (char*) malloc(1);
    chunk.size = 0;
    make_arg(url, props);
    curl_easy_reset(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, read_http_resp);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    if (verbose)
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    switch(method)
    {
        case REQ_GET:
            break;
        case REQ_DELETE:
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
            if (payload != NULL)
              curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
            break;
        case REQ_PUT:
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
            if (payload != NULL)
            {
              curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
            }
            break;
        case REQ_POST:
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            if (payload != NULL)
            {
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
            }
            if (formpost) {
                struct curl_slist *headerlist=NULL;
                static const char buf[] = "Content-Type: multipart/form-data;";
                headerlist = curl_slist_append(headerlist, buf);
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
                curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
            }
            break;
    }
    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK)
    {
        free(chunk.memory);
        current_response.m_err_code = ERR_CURL_RESP;
        current_response.m_err_msg = realloc(current_response.m_err_msg, strlen(curl_easy_strerror(res)));
        strcpy(current_response.m_err_msg, curl_easy_strerror(res));
        return ERR_CURL_RESP;
    }
    if(method == REQ_PUT)
    {
        // if server responds with HTTP 303, we should use GET and CURLOPT_FOLLOWLOCATION does not help
        char *redirect_url = 0;
        if(curl_easy_getinfo(curl, CURLINFO_REDIRECT_URL, &redirect_url) == CURLE_OK && redirect_url)
        {
            free(chunk.memory);
            chunk.memory = (char*) malloc(1);
            chunk.size = 0;
            curl_easy_setopt(curl, CURLOPT_URL, redirect_url);
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, NULL);
            CURLcode res = curl_easy_perform(curl);
            if(res != CURLE_OK)
            {
                free(chunk.memory);
                setCurrentResponse(ERR_CURL_RESP, curl_easy_strerror(res), strlen(curl_easy_strerror(res)));
                return ERR_CURL_RESP;
            }
        }
    }
    if(chunk.size == 0)
    {
        free(chunk.memory);
        setCurrentResponse(ERR_CURL_EMPTY, szEmptyResponse, strlen(szEmptyResponse));
        return ERR_CURL_EMPTY;
    }
    current_response.m_raw_resp = realloc(current_response.m_raw_resp, chunk.size+1);
    strcpy(current_response.m_raw_resp, chunk.memory);
    current_response.m_raw_resp[chunk.size] = '\0';
    free(chunk.memory);
    current_response.m_json_resp = json_tokener_parse(current_response.m_raw_resp);
    if (json_object_is_type(current_response.m_json_resp, json_type_null) ||
        !strcmp(current_response.m_raw_resp, json_object_get_string(current_response.m_json_resp)))
    {
        setCurrentResponse(ERR_JSON, szParseError, strlen(szParseError));
        return ERR_JSON;
    }
    return CURLE_OK;
}

/* ROUTES */
int get_route_q(int offset, int limit)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "offset", json_object_new_int(offset));
    json_object_object_add(props, "limit", json_object_new_int(limit));

    strcpy(url, R4_API_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_multiple_routes()
{
    char url[2048];
    int limit = 10, offset = 0;

    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "limit", json_object_new_int(limit));
    json_object_object_add(props, "offset", json_object_new_int(offset));
    strcpy(url, R4_API_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_route_by_id(const char *route_id)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));
    strcpy(url, ROUTE_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_route_path_points(const char *route_id, const char *route_path_output)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));
    json_object_object_add(props, "route_path_output", json_object_new_string(route_path_output));
    strcpy(url, ROUTE_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_route_directions(const char *route_id, int directions)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));
    json_object_object_add(props, "directions", json_object_new_int(directions));
    strcpy(url, ROUTE_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_route_query(const char *route_id, const char *query)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));
    json_object_object_add(props, "query", json_object_new_string(query));
    strcpy(url, ROUTE_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int update_route(const char *route_id, const char *dest_id, char *data)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));
    json_object_object_add(props, "route_destination_id", json_object_new_string(dest_id));
    strcpy(url, ROUTE_HOST);
    return request(REQ_PUT, curl, url, props, data);
}

int duplicate_route(const char *route_id, const char *to)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));
    json_object_object_add(props, "to", json_object_new_string(to));
    strcpy(url, DUPLICATE_ROUTE);
    return request(REQ_GET, curl, url, props, NULL);
}

int delete_route(const char *route_id)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));
    strcpy(url, ROUTE_HOST);
    return request(REQ_DELETE, curl, url, props, NULL);
}

int merge_routes(const char *route_ids, const char *depot_address, struct MapPoint point, int remove_origin)
{
    //TODO: Implement
    return -1;
}

int share_routes(const char *route_id, const char *email, const char *format)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));
    json_object_object_add(props, "format", json_object_new_string(format));

    struct curl_httppost *lastptr=NULL;

    curl_formadd(&formpost,
                   &lastptr,
                   CURLFORM_COPYNAME, "recipient_email",
                   CURLFORM_COPYCONTENTS, email,
                   CURLFORM_END);

    strcpy(url, SHARE_HOST);
    return request(REQ_POST, curl, url, props, NULL);
}

int get_address(const char *route_id, const char *destination_id)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));
    json_object_object_add(props, "route_destination_id", json_object_new_string(destination_id));
    strcpy(url, ROUTE_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int add_route_notes(const char *route_id, const char *destination_id, const char *notes, const char* device_type,
                    const struct MapPoint* point, const char *data)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));
    json_object_object_add(props, "address_id", json_object_new_string(destination_id));
    json_object_object_add(props, "dev_lat", json_object_new_int(point->lat));
    json_object_object_add(props, "dev_lng", json_object_new_int(point->lng));
    json_object_object_add(props, "device_type", json_object_new_string(device_type));
    strcpy(url, ADD_ROUTE_NOTES);
    return request(REQ_POST, curl, url, props, data);
}

int get_route_notes(const char *route_id, const char *destination_id)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));
    json_object_object_add(props, "route_destination_id", json_object_new_string(destination_id));
    strcpy(url, ADDRESS_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int set_gps(json_object* props)
{
    char url[2048];
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, GPS_HOST);
    return request(REQ_POST, curl, url, props, NULL);
}

/* OPTIMIZATIONS */
int add_optimization(const char* body)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, R4_API_HOST);
    return request(REQ_POST, curl, url, props, body);
}

int run_optimization(const json_object* addresses, const json_object* parameters)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));

    json_object* body = json_object_new_object();
    json_object_object_add(body, "addresses", addresses);
    json_object_object_add(body, "parameters", parameters);

    strcpy(url, R4_API_HOST);
    return request(REQ_POST, curl, url, props, json_object_to_json_string(body));
}

int reoptimize(const char *opt_id)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "optimization_problem_id", json_object_new_string(opt_id));
    json_object_object_add(props, "reoptimize", json_object_new_int(1));
    strcpy(url, R4_API_HOST);
    return request(REQ_PUT, curl, url, props, NULL);
}

int get_optimization(const char *optimization_problem_id)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "optimization_problem_id", json_object_new_string(optimization_problem_id));
    strcpy(url, R4_API_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_optimizations(const char *states, int offset, int limit)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "states", json_object_new_string(states));
    json_object_object_add(props, "offset", json_object_new_int(offset));
    json_object_object_add(props, "limit", json_object_new_int(limit));
    strcpy(url, R4_API_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int remove_optimization(const char *fields)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, R4_API_HOST);
    return request(REQ_GET, curl, url, props, fields);
}

int add_address_to_optimization(const char *body, const char *opt_id, int reoptimize)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "optimization_problem_id", json_object_new_string(opt_id));
    json_object_object_add(props, "reoptimize", json_object_new_int(reoptimize));

    strcpy(url, R4_API_HOST);
    return request(REQ_PUT, curl, url, props, body);
}

int remove_address_from_optimization(const char *address, const char *opt_id)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "optimization_problem_id", json_object_new_string(opt_id));
    json_object_object_add(props, "route_destination_id", json_object_new_string(address));
    strcpy(url, ADDRESS_HOST);
    return request(REQ_DELETE, curl, url, props, NULL);
}

/* ACTIVITIES */
int get_all_activities(const struct Limit* pLimit)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "offset", json_object_new_int(pLimit->offset));
    json_object_object_add(props, "limit", json_object_new_int(pLimit->limit));
    strcpy(url, ACTIVITIES_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_team_activities(const char *route_id, const char *team)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));
    json_object_object_add(props, "team", json_object_new_string(team));
    strcpy(url, ACTIVITIES_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int log_custom_activity(const char *route_id, const char *activity_type, const char *activity_message)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));

    json_object* body = json_object_new_object();
    json_object_object_add(props, "activity_type", json_object_new_string(activity_type));
    json_object_object_add(props, "activity_message", json_object_new_string(activity_message));

    strcpy(url, ACTIVITIES_HOST);
    return request(REQ_GET, curl, url, props, body);
}

int get_activity_by_type(const char *type)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "type", json_object_new_string(type));

    strcpy(url, ACTIVITIES_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

/* USERS */
int get_all_users()
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, USERS_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int authenticate_user(const struct Member *pMember)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));

    struct curl_httppost *lastptr=NULL;

    curl_formadd(&formpost,
                   &lastptr,
                   CURLFORM_COPYNAME, "strEmail",
                   CURLFORM_COPYCONTENTS, pMember->email,
                   CURLFORM_END);
    curl_formadd(&formpost,
                   &lastptr,
                   CURLFORM_COPYNAME, "strPassword",
                   CURLFORM_COPYCONTENTS, pMember->password1,
                   CURLFORM_END);
    curl_formadd(&formpost,
                   &lastptr,
                   CURLFORM_COPYNAME, "format",
                   CURLFORM_COPYCONTENTS, pMember->format,
                   CURLFORM_END);
    strcpy(url, AUTHENTICATION_HOST);
    return request(REQ_POST, curl, url, props, NULL);
}

int modify_user(const char *data, enum ReqType req)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, USERS_HOST);
    return request(req, curl, url, props, data);
}

int validate_session(const char *session_id, const char *member_id, const char *format)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "session_guid", json_object_new_string(session_id));
    json_object_object_add(props, "member_id", json_object_new_string(member_id));
    json_object_object_add(props, "format", json_object_new_string(format));
    strcpy(url, VALIDATE_SESSION);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_subusers()
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, USERS_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

/* TRACKING */
int asset_tracking(const char *id)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "tracking", json_object_new_string(id));
    strcpy(url, TRACKING_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_device_location(const char *route_id, int start_date, int end_date, const char *period,
                        int last_position, const char *format)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "route_id", json_object_new_string(route_id));
    json_object_object_add(props, "format", json_object_new_string(format));
    json_object_object_add(props, "last_position", json_object_new_int(last_position));
    json_object_object_add(props, "time_period", json_object_new_string(period));
    json_object_object_add(props, "start_date", json_object_new_int(start_date));
    json_object_object_add(props, "end_date", json_object_new_int(end_date));
    strcpy(url, LOCATION_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int batch_geocoding(const char *addresses, const char *format)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "addresses", json_object_new_string(addresses));
    json_object_object_add(props, "format", json_object_new_string(format));
    strcpy(url, GEOCODER);
    return request(REQ_POST, curl, url, props, json_object_new_object());
}

int reverse_geocoding(const char *addresses, const char *format)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "addresses", json_object_new_string(addresses));
    json_object_object_add(props, "format", json_object_new_string(format));
    strcpy(url, GEOCODER);
    return request(REQ_POST, curl, url, props, json_object_new_object());
}

/* STREETS */
int get_street_address(int seqno)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, STREETS_HOST);
    char szSeqno[10] = "";
    sscanf(szSeqno, "%d", &seqno);
    strcat(url, szSeqno);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_all_streets(const struct Limit *pLimit)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, STREETS_HOST);
    if (pLimit != NULL)
    {
        char szLimit[10] = "";
        sscanf(szLimit, "%d/%d/", &pLimit->limit, pLimit->offset);
        strcat(url, szLimit);
    }
    return request(REQ_GET, curl, url, props, NULL);
}

/* AVOIDANCE ZONES */
int add_avoidance_zone(const char *id, json_object *body)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "territory_id", json_object_new_string(id));
    strcpy(url, AVOIDANCE_HOST);
    return request(REQ_POST, curl, url, props, body);
}

int get_avoidance_zone(const char *id)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "territory_id", json_object_new_string(id));
    strcpy(url, AVOIDANCE_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_avoidance_zones()
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, AVOIDANCE_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int update_avoidance_zone(const char *id, json_object *body)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "territory_id", json_object_new_string(id));
    strcpy(url, AVOIDANCE_HOST);
    return request(REQ_PUT, curl, url, props, body);
}

int remove_avoidance_zone(const char *id)
{
    char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "territory_id", json_object_new_string(id));
    strcpy(url, AVOIDANCE_HOST);
    return request(REQ_DELETE, curl, url, props, NULL);
}

/* VEHICLES */
int get_vehicles(const struct Limit* pLimit)
{
    /*TODO: According to RFC-2616 length of URI is not limited.
            This number should be revised.
     */
    static char url[2048];
    json_object* props = json_object_new_object();  

    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    if (pLimit)
    {
       json_object_object_add(props, "offset", json_object_new_int(pLimit->offset));
       json_object_object_add(props, "limit", json_object_new_int(pLimit->limit));
    }

    strcpy(url, VEHICLES_SERVICE);
    return request(REQ_GET, curl, url, props, NULL);
}

/* ORDERS */
int add_order(json_object *data)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, ORDER_HOST);
    return request(REQ_POST, curl, url, props, data);
}

int add_order_to_route(const char *id, json_object *data, int redirect)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "redirect", json_object_new_int(redirect));
    json_object_object_add(props, "route_id", json_object_new_string(id));
    strcpy(url, ROUTE_HOST);
    return request(REQ_PUT, curl, url, props, data);
}

int get_order(const char *id)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "id", json_object_new_string(id));
    strcpy(url, ORDER_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_all_orders()
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, ORDER_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_orders_by_date(const char *date, int redirect)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "redirect", json_object_new_int(redirect));
    json_object_object_add(props, "day_added_YYMMDD", json_object_new_string(date));
    strcpy(url, ORDER_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_orders_by_scheduled(const char *date, int redirect)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "redirect", json_object_new_int(redirect));
    json_object_object_add(props, "scheduled_for_YYMMDD", json_object_new_string(date));
    strcpy(url, ORDER_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_orders_query(const char *query, const struct Limit *pLimit)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "query", json_object_new_string(query));
    json_object_object_add(props, "offset", json_object_new_int(pLimit->offset));
    json_object_object_add(props, "limit", json_object_new_int(pLimit->limit));
    strcpy(url, ORDER_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_custom_orders(const char *fields, const struct Limit *pLimit)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "fields", json_object_new_string(fields));
    json_object_object_add(props, "offset", json_object_new_int(pLimit->offset));
    json_object_object_add(props, "limit", json_object_new_int(pLimit->limit));
    strcpy(url, ORDER_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int update_order(json_object *data, int redirect)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "redirect", json_object_new_int(redirect));
    strcpy(url, ORDER_HOST);
    return request(REQ_PUT, curl, url, props, data);
}

int remove_order(json_object *data, int redirect)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "redirect", json_object_new_int(redirect));
    strcpy(url, ORDER_HOST);
    return request(REQ_DELETE, curl, url, props, data);
}

/* CONFIGURATION */
int get_config(const char *key)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    if (!str_empty(key))
    {
        json_object_object_add(props, "config_key", json_object_new_string(key));
    }
    strcpy(url, CONFIG_SERVICE);
    return request(REQ_GET, curl, url, props, NULL);
}

int modify_config(const char* value, enum ReqType method)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, CONFIG_SERVICE);
    return request(method, curl, url, props, value);
}

/* FILES */
int preview_file(const char *id, const char *format)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "strUploadID", json_object_new_string(id));
    json_object_object_add(props, "format", json_object_new_string(format));
    strcpy(url, PREVIEW_SERVICE);
    return request(REQ_GET, curl, url, props, NULL);
}

int upload_file(const char *file_name, const char *format)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "format", json_object_new_string(format));

    strcpy(url, UPLOAD_SERVICE);
    json_object* body = json_object_new_object();
    json_object_object_add(props, "strFilename", json_object_new_string(file_name));
    return request(REQ_POST, curl, url, props, body);
}

/* Territories */
int add_territory(const char *json_body)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, TERRITORY_HOST);
    return request(REQ_POST, curl, url, props, json_body);
}

int get_territory(const char *id)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "territory_id", json_object_new_string(id));

    strcpy(url, TERRITORY_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_all_territories()
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));

    strcpy(url, TERRITORY_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int remove_territory(const char *id)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "territory_id", json_object_new_string(id));

    strcpy(url, TERRITORY_HOST);
    return request(REQ_DELETE, curl, url, props, NULL);
}

/* ADDRESS BOOK */
int add_address_book_contact(const char *json_body)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    strcpy(url, ADDRESS_BOOK_HOST);
    return request(REQ_POST, curl, url, props, json_body);
}

int get_address_book_by_text(const char *text, const struct Limit* pLimit)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "limit", json_object_new_int(pLimit->limit));
    json_object_object_add(props, "offset", json_object_new_int(pLimit->offset));
    json_object_object_add(props, "query", json_object_new_string(text));
    strcpy(url, ADDRESS_BOOK_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_address_book_contacts(const char *id)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "address_id", json_object_new_string(id));
    strcpy(url, ADDRESS_BOOK_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int get_all_address_book_contacts(const struct Limit *pLimit)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "limit", json_object_new_int(pLimit->limit));
    json_object_object_add(props, "offset", json_object_new_int(pLimit->offset));
    strcpy(url, ADDRESS_BOOK_HOST);
    return request(REQ_GET, curl, url, props, NULL);
}

int update_address_book_contact(const char *id, const char *json_body)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "address_id", json_object_new_string(id));
    strcpy(url, ADDRESS_BOOK_HOST);
    return request(REQ_PUT, curl, url, props, json_body);
}

int remove_address_book_contact(const char *id)
{
    static char url[2048];
    json_object* props = json_object_new_object();
    json_object_object_add(props, "api_key", json_object_new_string(m_key));
    json_object_object_add(props, "address_id", json_object_new_string(id));
    strcpy(url, ADDRESS_BOOK_HOST);
    return request(REQ_DELETE, curl, url, props, NULL);
}
