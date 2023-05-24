#ifndef PRINTER_H
#define PRINTER_H
#include "WString.h"
#include "HardwareSerial.h"

class Debug{
  public:
    Debug()=default;
    template<typename T>
    void print(T data);

    template<typename T>
    void print(T *data);

    template<typename T>
    void println(T data);

    template<typename T>
    void println(T *data);

    template<typename T>
    void write(T data);

    template<typename T,typename N>
    void printf(T data,N format);
};



extern Debug Printer;


#endif