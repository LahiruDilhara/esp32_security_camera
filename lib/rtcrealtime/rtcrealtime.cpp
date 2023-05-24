#include "HardwareSerial.h"
#include "rtcrealtime.h"
#include "Wire.h"
#include "sdcard.h"
#include "printer.h"


void initClock(){
  
  Printer.println("\nInitializing clock");
  Printer.print("\t");
  Wire.begin(14,15);
  displayTime();
  Printer.println("\tClock inititalized succussfully\n");
  // setTime(54, 55, 11, 4, 27, 4, 23);
}

static void simpleClockInitializer(){
 Wire.begin(14,15); 
}

void getTime(int *second, int *minute, int *hour, int *day, int *date, int *month, int *year){
  delay(10);
  switchtoclock();
  Wire.beginTransmission(RTCAddress);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(RTCAddress,7);
  *second = bcd2dec(Wire.read() & 0x7F);
  *minute= bcd2dec(Wire.read());
  *hour= bcd2dec(Wire.read() & 0x3F);
  *day = bcd2dec(Wire.read());
  *date= bcd2dec(Wire.read());
  *month= bcd2dec(Wire.read());
  *year= bcd2dec(Wire.read());
  switchtosd();
}
int bcd2dec(int data){
  return ((data/16*10)+(data%16));
}
int dec2bcd(int data){
  return ((data/10*16)+(data%10));
}
void setTime(int second, int minute, int hour, int day, int date, int month, int year){
  switchtoclock();
  Printer.println("Setiing clock time....\n");
  Printer.print("\tNow the time is = ");
  displayTime();
  switchtoclock();
  Wire.beginTransmission(RTCAddress);
  Wire.write(0);
  Wire.write(dec2bcd(second));
  Wire.write(dec2bcd(minute));
  Wire.write(dec2bcd(hour));
  Wire.write(dec2bcd(day));
  Wire.write(dec2bcd(date));
  Wire.write(dec2bcd(month));
  Wire.write(dec2bcd(year));
  Wire.endTransmission();
  Printer.println("\tClock time set succusfully");
  Printer.print("\tNow the set time is = ");
  displayTime();
  Printer.print("\n");
}

void displayTime(){
  int second,minutes,hour,day,date,month,year;
  getTime(&second,&minutes,&hour,&day,&date,&month,&year);
  Printer.print("Seconds = ");
  Printer.print(second);
  Printer.print("\t");
  Printer.print("Minutes = ");
  Printer.print(minutes);
  Printer.print("\t");
  Printer.print("Hour = ");
  Printer.print(hour);
  Printer.print("\t");
  Printer.print("Day = ");
  Printer.print(day);
  Printer.print("\t");
  Printer.print("Date = ");
  Printer.print(date);
  Printer.print("\t");
  Printer.print("Month = ");
  Printer.print(month);
  Printer.print("\t");
  Printer.print("Year = ");
  Printer.println(year);
}

void clearClockBuffer(){
  Wire.beginTransmission(RTCAddress);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(RTCAddress,7);
  for(int i = 0;i<7;i++){
    Wire.read();
  }
}

void switchtosd(){
  Wire.end();
  delay(5);
  simpleSdInitializer();
  delay(5);
}
void switchtoclock(){
  sdunInit();
  delay(5);
  simpleClockInitializer();
  clearClockBuffer();
  delay(5);
}
