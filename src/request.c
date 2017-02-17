
#include <curl/curl.h>
#include <json.h>
#include "../include/route4me.h"
#include <string.h>

static char szEmptyResponse[] = "empty http response";
static char szParseError[] = "json parse error(s)\n";
static char szAPIError[] = "route4me api errors:";

// TODO: Revise api key length
char m_key[100];
void* curl;
static int verbose;
struct curl_httppost *formpost = NULL;

void init(char* szKey, int nVerbose)
{
    strcpy(m_key, szKey);
    verbose = nVerbose;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
}

void cleanUp()
{
    if (formpost)
    {
      curl_formfree(formpost);
    }
    if (curl)
    {
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    cleanCurrentResponse();
}


static struct response_data current_response = {0};

struct response_data getCurrentResponse()
{
    return current_response;
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

void cleanCurrentResponse()
{
    if (current_response.m_err_msg != NULL)
    {
        free(current_response.m_err_msg);
    }
    memset(&current_response, 0, sizeof(struct response_data));
}

static void setCurrentResponse(int error_code, const char* error_message, int error_strlen)
{
    current_response.m_err_code = error_code;
    current_response.m_err_msg = realloc(current_response.m_err_msg, strlen(error_message) + 1);
    strcpy(current_response.m_err_msg, error_message);
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

static void make_arg(char *url, json_object* params)
{
        int first = 1;
        char temp[2048] = "";
        int i,j;
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


int request(enum ReqType method, void *curl, char *url, json_object *props, /*json_object* body*/
            const char* payload, struct curl_httppost *formpost, struct response_data current_response, int verbose)
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
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
            break;
        case REQ_PUT:
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
            break;
        case REQ_POST:

            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
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
                //setCurrentResponse(ERR_CURL_RESP, curl_easy_strerror(res), strlen(curl_easy_strerror(res)));
                return ERR_CURL_RESP;
            }
        }
    }
    if(chunk.size == 0)
    {
        free(chunk.memory);
        //setCurrentResponse(ERR_CURL_EMPTY, szEmptyResponse, strlen(szEmptyResponse));
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
        //setCurrentResponse(ERR_JSON, szParseError, strlen(szParseError));
        return ERR_JSON;
    }
    return CURLE_OK;
}
