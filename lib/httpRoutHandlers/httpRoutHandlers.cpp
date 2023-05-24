#include "HardwareSerial.h"
#include "httpRoutHandlers.h"
#include "jsonParser.h"
#include "mcamera.h"
#include "webserverhandler.h"
#include "WiFi.h"

const char* sdCardUsedFreePrecentages(){
  String arguments[]={"\"name\"","\"age\""};
  String values[]={"\"lahiru\"","24"};
  return jsonCreater(arguments,values,2);
}

void cameraStartHandler(WiFiClient *client){
  CAMERASTATE = true;
  sendHttpResponse(client,"running","text/plain");
}
void cameraStoptHandler(WiFiClient *client){
  CAMERASTATE = false;
  sendHttpResponse(client,"stop","text/plain");
}

void stateHandler(WiFiClient *client){
  if(CAMERASTATE){
      sendHttpResponse(client,"running","text/plain");
    }
    else{
      sendHttpResponse(client,"stop","text/plain");
    }
}