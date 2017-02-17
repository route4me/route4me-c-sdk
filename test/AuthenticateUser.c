
#include <stdio.h>
#include "../include/route4me.h"

static char key[] = "11111111111111111111111111111111";

int main(int argc, char* argv[])
{
    init(key, 0);

    struct Member member = {0};
    strcpy(member.email, "apitester@gmail.com");
    strcpy(member.format, "json");
    strcpy(member.first_name, "Alex");
    strcpy(member.last_name, "Hardworker");
    strcpy(member.password1, "crypto1");

    if (!authenticate_user(&member))
    {
       json_object* opt_lst = getJSONResponse();
       printf("%s\n", json_object_to_json_string(opt_lst));
    }

    struct response_data response = getCurrentResponse();
    printf("Return code: %d\n Response: %s\n", response.m_err_code, response.m_raw_resp);

    cleanUp();
	return 0;
}

