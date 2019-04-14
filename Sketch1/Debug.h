#ifndef INCLUDE_GUARD_ARDUINO_DEBUG
#define INCLUDE_GUARD_ARDUINO_DEBUG

#define USE_DEBUG_MODE
#ifdef USE_DEBUG_MODE
#define DEBUG_INIT() SerialUSB.begin(9600)
#define DEBUG_PRINT(S) SerialUSB.print(S);\
SerialUSB.print("\n")
#else
#define DEBUG_PRINT(S)
#endif

#endif
