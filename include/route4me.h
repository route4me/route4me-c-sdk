
#ifndef croute4me
#define croute4me route4me

#include <json.h>

void init(char*, int);
void cleanUp();

struct response_data
{
    char* m_raw_resp;    
    json_object* m_json_resp;
    char* m_err_msg;
    int m_err_code;
};

struct MapPoint
{
    double lat;
    double lng;
};

struct Limit
{
    int offset;
    int limit;
};

struct Member
{
    char email[40];
    char password1[50];
    char password2[50];
    char session_guid[100];
    char format[10];
    char plan[10];
    char member_type[10];
    char industry[10];
    char first_name[20];
    char last_name[20];
    int check_terms;
    char device_type[20];
};

enum ReqType {
    REQ_GET,
    REQ_POST,
    REQ_PUT,
    REQ_DELETE
};

enum
{
    ERR_HTTP = -1,
    ERR_PARAM = -2,
    ERR_SYNTAX = -3,
    ERR_PARAM_TP = -4,
    ERR_CURL = -5,
    ERR_CURL_RESP = -6,
    ERR_CURL_EMPTY = -7,
    ERR_JSON = -8,
    ERR_API = -9,

    OPTIMIZATION_STATE_INITIAL = 1,
    OPTIMIZATION_STATE_MATRIX_PROCESSING = 2,
    OPTIMIZATION_STATE_OPTIMIZING = 3,
    OPTIMIZATION_STATE_OPTIMIZED = 4,
    OPTIMIZATION_STATE_ERROR = 5,
    OPTIMIZATION_STATE_COMPUTING_DIRECTIONS = 6,

    ROUTE4ME_METRIC_EUCLIDEAN = 1,
    ROUTE4ME_METRIC_MANHATTAN = 2,
    ROUTE4ME_METRIC_GEODESIC = 3,
    ROUTE4ME_METRIC_MATRIX = 4,
    ROUTE4ME_METRIC_EXACT_2D = 5,

    TSP = 1,
    VRP = 2,
    CVRP_TW_SD = 3,
    CVRP_TW_MD = 4,
    TSP_TW = 5,
    TSP_TW_CR = 6,
    BBCVRP = 7
};

struct response_data getCurrentResponse();
int getErrorCode();
char* getErrorMessage();
char* getRawResponse();
json_object* getJSONResponse();

/* Routes functionality */

/** \brief Get single route
 * \param offset
 * \param limit
 * \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_route_q(int offset, int limit);

/** \brief Gets a status update on all
* optimization problems for a specific API key.
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_multiple_routes();

/** \brief Gets a Route by ID.
* \param route_id route ID
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_route_by_id(const char *route_id);

/** \brief Gets info about a Route.
* \param props api call parameters
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_route(json_object* props);

/** \brief Gets routes by path points
* \param route id
* \param route_path_outputtest/SetGps.c
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_route_path_points(const char* route_id, const char* route_path_output);

/** \brief Gets routes by directions
* \param route id
* \param directions - 1 or 0
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_route_directions(const char* route_id, int directions);

/** \brief Gets routes by query
* \param route id
* \param query - text pattern
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_route_query(const char* route_id, const char* query);

/** \brief Add address to specific route
* \param route id
* \param address as JSON object
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int add_route_destinations(const char*, json_object*);

/** \brief Remove address from system
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int remove_address_from_route(const char* route_id, const char* destination_id);

/** \brief Update route with JSON data
* \param route id
* \param destination id
* \param JSON object
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int update_route(const char* route_id, const char* dest_id, char* data);

/** \brief Clone the route
* \param route id
* \param to - redirect to page or return JSON for "none"
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int duplicate_route(const char* route_id, const char* to);

/** \brief Delete a Route by ID.
* \param route_id route ID
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int delete_route(const char *route_id);

/** \brief Merge routes
* \param route_ids - comma separated list of routes
* \param depot_address
* \param point - lattitide and longtitude of depot
* \param remove_origin
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int merge_routes(const char* route_ids, const char* depot_address, struct MapPoint point, int remove_origin);

/** \brief Share route
* \param route_id route ID
* \param email - send route data there
* \param format
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int share_routes(const char* route_id, const char* email, const char* format);

/** \brief Returns route destination details.
* \param route_id
* \param destination id
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_address(const char* route_id, const char* destination_id);

/** \brief Add route notes
* \param route_id
* \param destination id
* \param text notes
* \param point on map
* \param device type
* \param JSON data to be added
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int add_route_notes(const char *route_id, const char *destination_id, const char *notes, const char* device_type,
                    const struct MapPoint* point, const char *data);

/** \brief Get route notes
* \param route_id
* \param destination id
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_route_notes(const char* route_id, const char* destination_id);

/** \brief Set GPS point.
* \param props api call parameters
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int set_gps(json_object* props);

/** \brief Create new optimization
* \param optimization data
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int add_optimization(const char* body);

/** \brief Reoptimize the problem.
* \param opt_id optimization problem ID
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int reoptimize(const char *opt_id);

/** \brief Returns optimization problem.
* \param optimization problem id
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_optimization(const char* optimization_problem_id);

/** \brief Returns optimization problem.
* \param states list of addresses for the optimization problem
* \param offset
* \param limit
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_optimizations(const char* states, int offset, int limit);

/** \brief Removes optimization problem.
* \param fields
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int remove_optimization(const char* fields);

/** \brief Removes address from optimization problem.
* \param address - id of the address
* \param opt_id - id of the problem
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int remove_address_from_optimization(const char* address, const char* opt_id);

/** \brief Adds address to optimization problem.
 * * \param opt_id - id of the problem
* \param body - address data in JSON format
* \param reoptimize
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int add_address_to_optimization(const char* opt_id, const char* body, int reoptimize);

/** \brief Get all activities
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_all_activities(const struct Limit*);

/** \brief Get all activities
 * \param route id
 * \param team
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_team_activities(const char* route_id, const char* team);

/** \brief Log custom activity
 * \param route id
 * \param activity type
 * \param message for log
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int log_custom_activity(const char *route_id, const char *activity_type,
                        const char *activity_message);

/** \brief Get activity type
 * \param activity type
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_activity_by_type(const char* type);

/** \brief Get all users
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_all_users();

/** \brief Authenticate users
 * \param member data
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int authenticate_user(const struct Member*);

/** \brief Modify user
 * \param member data
 * \param type of http request
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int modify_user(const char* data, enum ReqType);

/** \brief Validate session
 * \param session id
 * \param member id
 * \param format
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int validate_session(const char *session_id, const char *member_id, const char *format);

/** \brief Get subusers
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_subusers();

/** \brief Asset Tracking
 * \param id of asset
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int asset_tracking(const char* id);

/** \brief Get device location
 * \param route id
 * \param start date
 * \param end date
 * \param period
 * \param last position\
 * \param format
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_device_location(const char *route_id, int start_date, int end_date,
                        const char *period, int last_position, const char *format);

/** \brief Batch geocoding
 * \param addresses
 * \param format
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int batch_geocoding(const char *addresses, const char *format);

/** \brief Reverse geocoding
 * \param addresses
 * \param format
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int reverse_geocoding(const char *addresses, const char *format);

/** \brief Get street address
 * \param seqno
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_street_address(int seqno);

/** \brief Get all streets
 * \param limit
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_all_streets(const struct Limit* pLimit);

/** \brief Add avoidance zone
 * \param id
 * \param body
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int add_avoidance_zone(const char* id, json_object* body);

/** \brief Get avoidance zone
 * \param id
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_avoidance_zone(const char* id);

/** \brief Get avoidance zones
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_avoidance_zones();

/** \brief Update avoidance zone
 * \param id
 * \param body
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int update_avoidance_zone(const char* id, json_object* body);

/** \brief Remove avoidance zone

 * \param id
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int remove_avoidance_zone(const char* id);

/** \brief Add order
 * \param JSON data
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int add_order(json_object*);

/** \brief Add order to route
 * \param id
 * \param JSON data
 * \param redirect
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int add_order_to_route(const char*, json_object*,int);

/** \brief Get order
 * \param id
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_order(const char*);

/** \brief Get all orders
 * \param id
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_all_orders();

/** \brief Remove order
 * \param JSON data
 * \param redirect
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int remove_order(json_object* data, int redirect);

/** \brief Get all orders
 * \param JSON data
 * \param redirect
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int update_order(json_object* data, int redirect);

/** \brief Get all orders by date range
 * \param date
 * \param int redirect
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_orders_by_date(const char* date, int redirect);

/** \brief Get orders by scheduled date
 * \param date
 * \param redirect
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_orders_by_scheduled(const char* date, int redirect);

/** \brief Get orders by custom field
 * \param field
 * \param limit
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_custom_orders(const char *fields, const struct Limit* pLimit);

/** \brief Get orders by query
 * \param query
 * \param limit
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_orders_query(const char *query, const struct Limit* pLimit);

/** \brief Get configuration
 * \param key
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_config(const char *key);

/** \brief Modify configuration
 * \param value
 * \param method
 * \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int modify_config(const char* value, enum ReqType method);

/** \brief Get vehicles
 * \param limit
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_vehicles(const struct Limit* pLimit);

/** \brief Preview file
 * \param id
 * \param format
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int preview_file(const char* id, const char* format);

/** \brief Upload file
 * \param file_name
 * \param format
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int upload_file(const char* file_name, const char* format);

/** \brief Add territory
 * \param territory id
 * \param JSON data
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int add_territory(const char* json_body);

/** \brief Get territory
 * \param territory id
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_territory(const char* id);

/** \brief Get all territories
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_all_territories();

/** \brief Remove territory
 * \param territory id
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int remove_territory(const char* id);

/** \brief Add contact to address book
 * \param JSON body
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int add_address_book_contact(const char* json_body);

/** \brief Get contact from address book by id
 * \param id
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_address_book_contacts(const char* id);

/** \brief Get contact from address book by text
 * \param text
 * \param limit
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_address_book_by_text(const char* text, const struct Limit* pLimit);

/** \brief Get address book contacts
 * \param text
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int get_all_address_book_contacts(const struct Limit*);

/** \brief Update address book contact
 * \param id
 * \param JSON body
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int update_address_book_contact(const char* id, const char* json_body);

/** \brief Remove address book contact
 * \param id
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int remove_address_book_contact(const char* id);

/** \brief Deserialize JSON file to string
 * \param input - file
 * \param output - data
* \return \c 0 if the response was successfully received, \c error code if an error occurred.
*/
int deserialize(const char* file, char** data);

#endif


