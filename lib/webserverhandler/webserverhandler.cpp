#include <sys/_stdint.h>
#include "WString.h"
#include "webserverhandler.h"
#include "webstie.h"
#include "printer.h"
#include "httpRoutHandlers.h"
#include "mcamera.h"

void handleWebRequest(WiFiClient *client){
  if(*client){
    CAMERASTATE=false;
    Printer.println("\nNew Client connected....");
    String currentLine = "";
    while(client->connected()){
      char c = client->read();
      Printer.write(c);
      if(c == '\n'){
        if(currentLine.length() == 0){
          sendHttpResponse(client,homePage.c_str(),"text/html");
          break;
        }
        else{
          currentLine="";
        }
      }
      else if(c != '\r'){
        currentLine += c;
      }
      route(currentLine,client);
    }
  }
}

void route(String &currentLine,WiFiClient *client){

  if(currentLine.endsWith("GET /start HTTP/1.1")){
    cameraStartHandler(client);
  }
  else if(currentLine.endsWith("GET /stop HTTP/1.1")){
    cameraStoptHandler(client);
  }
  else if(currentLine.endsWith("GET /state HTTP/1.1")){
    stateHandler(client);
  }
  else if(currentLine.endsWith("GET /json HTTP/1.1")){
    sendHttpResponse(client, sdCardUsedFreePrecentages(),"application/json");
  }

}

void sendHttpResponse(WiFiClient *client,const char *content,const char *content_type,int status_code,int content_length){
  String ResponseHeader = "HTTP/1.1 " + String(status_code) + " OK\r\n";
  ResponseHeader+= "Server: LKServer/1.0 (linux)\r\n";
  ResponseHeader+= "Connection: close\r\n";
  ResponseHeader+= "Accept-Ranges: bytes\r\n";
  ResponseHeader+= "Content-Type: " + String(content_type) + "\r\n";
  if(content_length){
    ResponseHeader+= "Content-Length: " + String(content_length) + "\r\n";
  }
  ResponseHeader+="\n\r";
  client->print(ResponseHeader.c_str());
  client->print(content);
  client->print("\n\r");
  client->flush();
  client->stop();
}

