#include "WString.h"
#include <WiFi.h>
#include "mwifi.h"
#include "printer.h"
#include "Esp.h"


int config(const char* SSID,const char* password){
  WiFi.softAPConfig(local_IP,gateway,subnet);
  if(!WiFi.softAP(SSID,password)){
    return 4;
  }
  else{
    return 0;
  }
}

void printwifidetails(){
  Printer.println("Wifi Access point Details");
  Printer.print("\tAccess point ip address = ");
  Printer.println(WiFi.softAPIP());
  Printer.print("\tAccess point SSID = ");
  Printer.println(WiFi.softAPSSID());
  Printer.print("\n");
}

bool createWifiAp(const char* SSID,const char* password){
  if(config(SSID,password)==0){
    Printer.println("\nAccess point created Sucsussfully");
    printwifidetails();
    return true;
  }
  else{
    Printer.println("Error occoured when creating access point");
    ESP.restart();
  }
  return false;
}
