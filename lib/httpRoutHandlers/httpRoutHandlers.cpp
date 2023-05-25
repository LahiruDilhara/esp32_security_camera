#include "HardwareSerial.h"
#include "httpRoutHandlers.h"
#include "jsonParser.h"
#include "mcamera.h"
#include "webserverhandler.h"
#include "WiFi.h"
#include "sdcard.h"

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

void sdCardDetailsHandler(WiFiClient *client){
  String arguments[]={"\"totalcapacity\"","\"usedcapacity\"","\"usablecapacity\"","\"freecapacity\""};
  String totalcapacity = String(SdTotalCapacity('M'));
  double usedcapacity = SdUsedCapacity('M');
  double usablecapacity = SdTotalUsableCapacity('M');
  double freecapacity = usablecapacity-usedcapacity;
  String values[]={totalcapacity.c_str(),String(usedcapacity).c_str(),String(usablecapacity).c_str(),String(freecapacity).c_str()};

  sendHttpResponse(client, jsonCreater(arguments,values,4),"application/json");


}

void sdCardFormatter(WiFiClient *client){
  if(formatSD()){
    sendHttpResponse(client,"formatted","text/plain");
  }
  else{
    sendHttpResponse(client,"not formatted","text/plain");
  }
}