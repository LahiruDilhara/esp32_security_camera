#include "HardwareSerial.h"
#include "sleepesp.h"
#include "esp_sleep.h"
#include "esp_bt.h"
#include "WiFi.h"
#include "printer.h"

void gotosleep(){
  WiFi.mode(WIFI_OFF);
  btStop();
  Printer.println("Esp is entering to the deep sleep mode.good bye");
  esp_deep_sleep_start();
}