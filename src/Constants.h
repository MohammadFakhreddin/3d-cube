#ifndef Constants_class
#define Constants_class
//
// Created by mohammad.fakhreddin on 1/3/20.
//
#include <math.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    //define something for Windows (32-bit and 64-bit, this part is common)
#define __PLATFORM_WIN__
#define __DESKTOP__

#ifdef _WIN64
   //define something for Windows (64-bit only)
#else
   //define something for Windows (32-bit only)
#endif

#elif __APPLE__
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
    // iOS Simulator
    // iOS device
#define __MOBILE__
#ifndef __IOS__
#define __IOS__
#endif
#elif TARGET_OS_MAC
    // Other kinds of Mac OS
#define __DESKTOP__
#define __PLATFORM_MAC__
#else
#   error "Unknown Apple platform"
#endif
#elif __ANDROID__
#define __MOBILE__
#elif __linux__
    // linux
#define __PLATFORM_LINUX__
#if !defined(__DESKTOP__)
#define __DESKTOP__
#endif
#elif __unix__ // all unices not caught above
    // Unix
#define __PLATFORM_UNIX__
#elif defined(_POSIX_VERSION)
    // POSIX
#else
#   error "Unknown compiler"
#endif

class Constants {

public:

  class Window {
  
  public:
	
    static constexpr char appName[] = "3D CUBE";
	
  };
  
  enum class Platform {
    Windows,
    Mac,
    Iphone,
    Android,
    Unknown
  };

#ifdef __DESKTOP__
  
  enum class Buttons
  {
    keyA,
    keyD,
    keyW,
    keyS,
    keyE,
    keyQ,
    keyR,
    keyT,
    keyF,
    keyG,
    keyX,
    keyC,
    keyV,
    keyB,
    keyU,
    keyH,
    keyJ,
    keyK,
    keyY,
    keyI,
    keyL,
    keyM,
    keyN,
    keyO,
    keyP,
    keyZ,
    tab,
    arrowLeft,
    arrowRight,
    arrowUp,
    arrowDown
  };

#endif // __DESKTOP__
};
#endif //!Constants_class
