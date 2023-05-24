#include "printer.h"
#include <WiFi.h>
#include "HardwareSerial.h"
#include "WString.h"


HardwareSerial &outputStream = Serial;



template<typename T>
void Debug::print(T data){
  outputStream.print(data);
}
template<typename T>
void Debug::print(T *data){
  outputStream.print(data);
}
template<typename T>
void Debug::write(T data){
  outputStream.write(data);
}
template<typename T>
void Debug::println(T data){
  outputStream.println(data);
}
template<typename T>
void Debug::println(T *data){
  outputStream.println(data);
}
template<typename T,typename N>
void Debug::printf(T data,N format){
  outputStream.printf(data,format);
}

extern Debug Printer = Debug();

template void Debug::print<int>(int);
template void Debug::print<const char>(const char *);
template void Debug::print<double>(double);

template void Debug::println<int>(int);
template void Debug::println<const char>(const char *);
template void Debug::println<IPAddress>(IPAddress);
template void Debug::println<String>(String);
template void Debug::println<double>(double);

template void Debug::write<char>(char);

template void Debug::printf<const char*,const char *>(const char *,const char *);
template void Debug::printf<const char*,String>(const char *,String);
template void Debug::printf<const char*,double>(const char*,double);
