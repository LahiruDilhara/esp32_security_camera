#include <sys/_stdint.h>
#ifndef HTMLCODE_H
#define HTMLCODE_H
#include "WiFi.h"
#include "WString.h"


void handleWebRequest(WiFiClient *);
void route(String&,WiFiClient*);
void sendHttpResponse(WiFiClient *client,const char *content,const char *content_type  = "text/plain",int status_code = 200,int content_length = 0);
#endif
