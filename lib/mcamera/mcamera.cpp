#include "HardwareSerial.h"
#include "esp_err.h"
#include "mcamera.h"
#include "esp_camera.h"
#include "printer.h"
#include "Esp.h"

bool CAMERASTATE=false;

bool cameraInit(){
  Printer.println("\n");
  Printer.println("Camera initialization started....");
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = 5;
  config.pin_d1 = 18;
  config.pin_d2 = 19;
  config.pin_d3 = 21;
  config.pin_d4 = 36;
  config.pin_d5 = 39;
  config.pin_d6 = 34;
  config.pin_d7 = 35;
  config.pin_xclk = 0;
  config.pin_pclk = 22;
  config.pin_vsync = 25;
  config.pin_href = 23;
  config.pin_sscb_sda = 26;
  config.pin_sscb_scl = 27;
  config.pin_pwdn = 32;
  config.pin_reset = -1;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_SVGA;
  config.jpeg_quality = 8;
  config.fb_count = 2;
  Printer.println("\tCamera setup succussfully");
  Printer.println("\tCamera init is starting....");

  esp_err_t error = esp_camera_init(&config);
  if(error != ESP_OK){
    Printer.println("\tCamera init unsuccessfull!");
    ESP.restart();
    return false;
  }
  else{
    Printer.println("\tCamera init succussfull\n");
    return true;
  }
}

camera_fb_t* takePhoto(){
  camera_fb_t *fb = nullptr;
  Printer.println("\nTaking a photo");
  fb = esp_camera_fb_get();
  if(!fb){
    Printer.println("\tFailed to take photo\n");
    ESP.restart();
  }
  else{
    Printer.println("\tSuccussfuly take a photo\n");

  }
  return fb;
}

void releasePhoto(camera_fb_t* fb){
  esp_camera_fb_return(fb);
}