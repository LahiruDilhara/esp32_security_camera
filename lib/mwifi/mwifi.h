#ifndef MWIFI_H
#define MWIFI_H
#include <WiFi.h>


static IPAddress local_IP(192,168,4,1);
static IPAddress gateway(192,168,4,1);
static IPAddress subnet(255,255,255,0);

int config(const char*,const char*);
void printwifidetails();
bool createWifiAp(const char*,const char*);

#endif