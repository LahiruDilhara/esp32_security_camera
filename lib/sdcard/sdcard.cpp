#include <cstddef>
#include "WString.h"
#include <sys/unistd.h>
#include "sd_defines.h"
#include <sys/_stdint.h>
#include "esp32-hal-gpio.h"
#include "esp32-hal.h"
#include "HardwareSerial.h"
#include "SD_MMC.h"
#include "sdcard.h"
#include "soc/soc.h"
#include "FS.h"
#include "stdint.h"
#include "rtcrealtime.h"
#include "Wire.h"
#include "printer.h"
#include "Esp.h"


// intitalization part of the sd card
bool sdInit(bool autoformat){
  Printer.println("\nSd card mount is being starting....");
  if(!SD_MMC.begin("/lahiru",true,autoformat)){
    Printer.println("\tSd card mount was failed\n");
    ESP.restart();
    return false;
  }
  Printer.println("\tSd card mounted successfully");
  return true;
}

void simpleSdInitializer(){
 if(!SD_MMC.begin("/lahiru",true)){
    ESP.restart();
  } 
}


void sdunInit(){
  SD_MMC.end();
}

// end of inititalization part

// format the sd card

bool formatSD(){
  Printer.print("Start Formatting the Sd card....\n");
  if(!removeContentRecursivly("/")){
    Printer.println("\tSd card Formating unsuccessful\n");
    return false;
  }
  Printer.println("\tSd card formated successfully.\n");
  return true;
}
// end of formating part

// info printing part of the sd card

void printSdInfo(){
  Printer.println("Sd card information");
  Printer.printf("\tSd card total capacity is %2.1lfGB.\n", SdTotalCapacity('G'));
  Printer.printf("\tSd card total usable capacity is %2.1lfGB\n", SdTotalUsableCapacity('G'));
  Printer.printf("\tSd card used capacity is %2.1lfGB\n", SdUsedCapacity('G'));
  Printer.printf("\tSd card type is %2s\n", SdCardType());
}
double SdTotalCapacity(char outPutType){
  return byte2type(outPutType, SD_MMC.cardSize());
}
double SdTotalUsableCapacity(char outPutType){
  return byte2type(outPutType,SD_MMC.totalBytes());
}
double SdUsedCapacity(char outPutType){
  return byte2type(outPutType, SD_MMC.usedBytes());
}
static String SdCardType(){
  switch(SD_MMC.cardType()){
    case CARD_SDHC:
      return "SDHC";
    case CARD_SD:
      return "SD";
    case CARD_NONE:
      return "NONE";
    case CARD_MMC:
      return "MMC";
    default:
      return "unknown";
  }
}
static double byte2type(char outPutType,uint64_t bytecapacity){
    switch(outPutType){
    case 'G': // for gigabyte
      bytecapacity = bytecapacity/(1024*1024*1024);
      return bytecapacity;
    case 'M': // for megabyte
      bytecapacity = bytecapacity/(1024*1024);
      return bytecapacity;
    case 'K': // for kilobyte
      bytecapacity = bytecapacity/1024;
      return bytecapacity;
    default:
      return bytecapacity;
  }
}

void printContent(const char* directoryPath,char type){
  Printer.printf("\nPrinting the content of %s\n",directoryPath);
  File directory = SD_MMC.open(directoryPath,"r");
  if(!directory){
    Printer.printf("\nFailed to open directory %s for print the content \n",directoryPath);
    ESP.restart();
  }
  while(File entry = directory.openNextFile()){
    if(entry.isDirectory() && (type == 'd' || type == 'a')){
      Printer.printf("\tDirectory : %s\n", entry.name());
    }
    else if(type == 'f' || type == 'a'){
      Printer.printf("\tFile : %s\n", entry.name());
    }
    entry.close();
  }
  directory.close();
  Printer.print("\n");
}

// end of info printing part

// starting of directory and file manipulation part

void mkdir(const char* directory){
  Printer.printf("\nCreting the directory %s\n",directory);
  if(SD_MMC.exists(directory)){
    Printer.println("\tThe directory already exists\n");
  }
  else{
    if(SD_MMC.mkdir(directory)){
      Printer.println("\tThe directory was created succussfully");
    }
    else{
      Printer.println("\tError createing directory");
      ESP.restart();
    }
  }
}



bool removeContent(const char *path){
  Printer.println("Removing the content....");
  if(fileType(path)){
    Printer.printf("\tContent is a directory and removing the directory %s\n",path);
    if(!SD_MMC.rmdir(path)){
      Printer.println("\tDirectory removing failed.\n");
      return false;
    }
    Printer.println("\tDirectory removed successfully.\n");
    return true;
  }
  else{
    Printer.println("\tContent is a file and removing the file..");
    if(!SD_MMC.remove(path)){
      Printer.println("\tFile removing failed.\n");
      return false;
    }
    Printer.println("\tFile removed successfully.\n");
    return true;
  }
}

bool removeContentRecursivly(const char *path){
  File content = SD_MMC.open(path);
  if(!content){
    Printer.printf("\tCannot open the %s \n",path);
    return false;
  }
  if(content.isDirectory()){
    while(File entry = content.openNextFile()){
      removeContentRecursivly(entry.path());
      entry.close();
    }
    if(String(path) != "/"){
      Printer.printf("\tRemoving Dir: %s\n",path);
      if(!(SD_MMC.rmdir(path))){
        Printer.printf("\t%s Could not be deleted\n",path);
        content.close();
        return false;
      }
    }
  }
  else{
    Printer.printf("\tRemoving File: %s\n",path);
    if(!(SD_MMC.remove(path))){
      Printer.printf("\t%s Could not be deleted\n",path);
      content.close();
      return false;
    }
  }
  content.close();
  return true;
}

// end of file and directory manipulation part


// starting of file read and write part

uint8_t* readContent(const char* path,size_t& filesize,uint32_t offset,uint32_t chunksize,uint32_t* readchunksize){
  Printer.printf("\nReading file %s \n",path);
  File file = SD_MMC.open(path);
  if(!file){
    Printer.printf("\tFile %s open unsuccessful\n",path);
    return nullptr;
  }
  filesize = file.size();
  size_t buffersize = filesize;
  int remaining = filesize - offset;
  if(remaining <=0){
    Printer.println("\tFile read unsuccessful.Offset is greater than filesize\n");
    return nullptr;
  }
  if(chunksize){
    file.seek(offset);
    if(remaining < chunksize){
      chunksize = remaining;
    }
    buffersize = chunksize;
  }
  else{
    chunksize = filesize;
  }
  uint8_t * buffer {new uint8_t[buffersize]};
  if(!buffer){
    file.close();
    Printer.println("\tFile read unsuccessful.Buffer not created\n");
    return nullptr;
  }
  size_t readbytes = file.read(buffer,buffersize);
  if(readbytes != chunksize){
    Printer.println("\tFile read unsuccessful.Read bytes count less than excpected bytes count\n");
    file.close();
    return nullptr;
  }
  file.close();
  if(readchunksize){
    *readchunksize = buffersize;
  }
  Printer.println("\tFile read successfully.\n");
  return buffer;
}

void writeToFile(const char* filename,uint8_t *buffer,size_t& buffersize){
  Printer.println("\nWriting to file");
  fs::File file = SD_MMC.open(filename,FILE_WRITE,true);
  if(!file){
    Printer.println("\tFailed to create file");
    ESP.restart();
  }
  else{
    file.write(buffer,buffersize);
    file.close();
    Printer.println("\tFile was written succussfully\n");
  }
}

bool appendToFile(const char* filename,uint8_t* buffer,uint32_t buffersize){
  Printer.println("\nAppending to file");
  fs::File file = SD_MMC.open(filename,FILE_APPEND,true);
  if(!file){
    Printer.println("\tFailed to create file\n");
    return false;
  }
  else{
    if(file.write(buffer,buffersize)){
      Printer.println("\tFile appended succesfully\n");
      return true;
    }
    else{
      Printer.println("\tFile appended unsuccessful.Not print to the file");
      return false;
    }

  }
}

bool fileType(const char *path){
  File object = SD_MMC.open(path,"r");
  if(!object){
    Printer.print("File/Directory cannot open");
    ESP.restart();
  }
  if(object.isDirectory()){
    object.close();
    return true;
  }
  else{
    object.close();
    return false;
  }
}

void releaseReadBuffer(uint8_t* buffer){
  delete[] buffer;
}