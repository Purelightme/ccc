#include "event2/http.h"
#include "event2/event.h"
#include "event2/buffer.h"
#include <stdio.h>
#include <stdlib.h>


void httpGenericCallback(struct evhttp_request* request,void* arg)
{
	const struct evhttp_uri* evhttp_uri = evhttp_request_get_evhttp_uri(request);
	char url[8192];
	evhttp_uri_join(evhttp_uri,url,8192);
	printf("accept request url:%s\n", url);
	struct evbuffer* buffer = evbuffer_new();
	if (!buffer)
	{
		printf("create buffer failed!\n");
	}
	evbuffer_add_printf(buffer,"Server response:url:%s",url);
	evhttp_send_reply(request,HTTP_OK,"OK",buffer);
	evbuffer_free(buffer);
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("usage:%s port\n", argv[0]);
		return 1;
	}
	int port = atoi(argv[1]);
	if (port == 0)
	{
		printf("port error:%s\n", argv[1]);
		return 2;
	}
	struct event_base* base = event_base_new();
	if (!base)
	{
		printf("create event_base failed\n");
		return 3;
	}
	struct evhttp* http = evhttp_new(base);
	if (!http)
	{
		printf("create http failed\n");
		return 4;
	}
	if (evhttp_bind_socket(http,"0.0.0.0",port) != 0)
	{
		printf("bind socket failed!port:%s\n", argv[1]);
		return 5;
	}
	evhttp_set_gencb(http,httpGenericCallback,NULL);
	event_base_dispatch(base);
	return 0;
}