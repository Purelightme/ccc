//
// Created by purelightme on 2020/6/23.
//

#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    CURLcode res;

    /* In windows, this will init the winsock stuff */
    curl_global_init(CURL_GLOBAL_ALL);

    /* get a curl handle */
    curl = curl_easy_init();
    CURLINFO info;
    char *ct;
    int *status;
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://dev.daishu-component.com/api/backend/store/stores/999999");
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
            return -1;
        }
        /* always cleanup */
        curl_easy_getinfo(curl,CURLINFO_RESPONSE_CODE,&status);
        printf("status:%d",status);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}