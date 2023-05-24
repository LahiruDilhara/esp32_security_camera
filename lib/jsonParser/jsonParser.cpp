#include <cstring>
#include "HardwareSerial.h"
#include "WString.h"
#include "jsonParser.h"



const char* jsonCreater(String arguments[],String values[],uint8_t argument_count){
  String JsonString = "";
  JsonString+="{\n";
  for(uint8_t i = 0;i<argument_count;i++){
    JsonString+="    ";
    JsonString+=arguments[i];
    JsonString+=":";
    JsonString+=values[i];
    if(i < argument_count-1){
      JsonString+=",";
    }
    JsonString+="\n";
  }
  JsonString+="}\n";
  char * JsonStringCopy = new char[JsonString.length()+1];
  strcpy(JsonStringCopy, JsonString.c_str());
  return JsonStringCopy;
}