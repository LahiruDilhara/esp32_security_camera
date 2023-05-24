#ifndef MCAMERA_H
#define MCAMERA_H
#include "esp_camera.h"

extern bool CAMERASTATE;

bool cameraInit();
camera_fb_t* takePhoto();
void releasePhoto(camera_fb_t*);


#endif