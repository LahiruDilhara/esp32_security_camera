#include "WString.h"
#include <sys/_types.h>
#include "esp32-hal.h"
#include "filehandler.h"
#include "sdcard.h"
#include "rtcrealtime.h"

static int MONTH=-1;
static int DAY=-1;
static int HOUR=-1;
static int MINUTES=0;
static int SECONDS=0;
static int MILIS=0;

static int newMonth=0;
static int newDay = 0;
static int newHour=0;



static void initTime(){
  int temp,temp1;
  int seconds=0;
  getTime(&seconds, &MINUTES, &newHour,&temp , &newDay, &newMonth, &temp1);
  if(seconds!=SECONDS){
    SECONDS=seconds;
    MILIS=0;
  }
  else{
    ++MILIS;
  }
}

String getFileName(){
  delay(10);
  initTime();
  String MONTH_="/"+String(newMonth);
  String MONTHDAY = MONTH_+"/"+String(newDay);
  String MONTHDAYHOUR = MONTHDAY+"/"+String(newHour);
  String fileName = "/"+String(MINUTES)+String(SECONDS)+String(MILIS)+".jpg";
  if(newMonth!=MONTH){
    MONTH=newMonth;
    mkdir(MONTH_.c_str());
  }
  if(newDay!=DAY){
    DAY=newDay;
    mkdir(MONTHDAY.c_str());
  }
  if(newHour!=HOUR){
    HOUR=newHour;
    mkdir(MONTHDAYHOUR.c_str());
  }
  return MONTHDAYHOUR+fileName;
}