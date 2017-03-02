
#include <stdio.h>
#include "../include/route4me.h"

static char key[] = "11111111111111111111111111111111";

int main(int argc, char* argv[])
{
    init(key, 1);
    const char file_name[] = "new_optimization.json";
    char* data = NULL;
    char id[100] = "";

    if (deserialize(file_name, &data))
    {
        printf("Data file is not found!\n");
        return -1;
    }

    if (!add_optimization(data))
    {
       json_object* opt_lst = getJSONResponse();
       json_object* opt_problem = json_object_object_get(opt_lst, "optimization_problem_id");
       printf("Optimization problem created: %s\n", json_object_to_json_string(opt_problem));
       strip_quotes(id, json_object_to_json_string(opt_problem));
       printf("id = %s\n", id);
       if (!reoptimize(id))
       {
           json_object* opt_lst = getJSONResponse();
           printf("%s\n", json_object_to_json_string(opt_lst));
       }
    }

    cleanUp();
	return 0;
}

