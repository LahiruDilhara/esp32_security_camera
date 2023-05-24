#ifndef RTCREALTIME_H
#define RTCREALTIME_H

#define RTCAddress 0x68

void initClock();
void getTime(int *,int *,int *,int *,int *,int *,int *);
int bcd2dec(int);
int dec2bcd(int);
void setTime(int second,int minute,int hour,int day,int date,int month,int year);
void displayTime();
void switchtosd();
void switchtoclock();
static void simpleClockInitializer();
void clearClockBuffer();

#endif