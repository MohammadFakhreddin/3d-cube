#ifndef STB_image_header
#define STB_image_header

#include "./../Constants.h"
#include "./open_gl_stb_image.h"
#include "../utils/log/Logger.h"
#include <string>
#ifdef __ANDROID__
#include "./../../android/app/src/main/cpp/AndroidEnvironment.h"
#endif
#include <assert.h>
#include <iostream>

class STBImageHelper{
public:
  static unsigned char * loadTexture(
    std::string textureAddress,
    int* width,
    int* height,
    int* numberOfChannels
  ){
      Logger::log("Loading image:"+textureAddress);
      #if defined(__DESKTOP__)
        return stbi_load(textureAddress.c_str(), width, height, numberOfChannels, STBI_rgb);
      #elif defined(__ANDROID__)
          return AndroidEnvironment::getInstance()->loadImage(
                  textureAddress,
                  width,
                  height,
                  numberOfChannels
          );
      #endif
      return NULL;
  }
};

#endif