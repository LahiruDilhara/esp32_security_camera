#ifndef SDCARD_H
#define SDCARD_H

#include <cstddef>
#include <sys/_stdint.h>
#include <stdio.h>
#include "WString.h"
#include <sys/_intsup.h>
#include "SD_MMC.h"
#include "soc/soc.h"
#include "FS.h"
#include "stdint.h"

typedef unsigned char unint8_t;

// sd card inititlaization part
bool sdInit(bool autoformat=false);
void simpleSdInitializer(); //  initialize without any debug information printing
void sdunInit(); // uninizialite the sd card


// sd card formatiing part
bool formatSD();

// sd card information prit
void printSdInfo();
double SdTotalCapacity(char outPutType); // total available space 
double SdTotalUsableCapacity(char outPutType); // total usable space in sd card when reduce filesystem and other factor capacities
double SdUsedCapacity(char outPutType); // used capacity of the sd card
static String SdCardType();
static double byte2type(char outPutType,uint64_t bytecapacity);
void printContent(const char* directoryPath,char type); // a=all content,f = file,d = directory

// sd card directory and file manipulation part
void mkdir(const char*);
bool removeContent(const char *path);
bool removeContentRecursivly(const char *path);

// sd card file read and write part
uint8_t* readContent(const char* path,size_t& filesize,uint32_t offset =0,uint32_t chunksize =0,uint32_t* readchunksize = nullptr);
void writeToFile(const char* filename,unint8_t *buffer,size_t& buffersize);
bool appendToFile(const char* filename,uint8_t* buffer,uint32_t buffersize);
bool fileType(const char *path); // return 1 if it is a directory else return 0
void releaseReadBuffer(uint8_t* buffer);


#endif