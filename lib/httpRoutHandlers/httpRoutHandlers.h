#ifndef HTTPROUTHANDLERS_H
#define HTTPROUTHANDLERS_H
#include "WString.h"
#include "WiFi.h"

const char* sdCardUsedFreePrecentages();
void cameraStartHandler(WiFiClient *client);
void cameraStoptHandler(WiFiClient *client);
void stateHandler(WiFiClient *client);
void sdCardDetailsHandler(WiFiClient *client);
void sdCardFormatter(WiFiClient *client);

#endif
