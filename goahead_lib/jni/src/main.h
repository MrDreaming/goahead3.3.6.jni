#ifndef _SRC_MAIN_H_
#define _SRC_MAIN_H_

#include<android/log.h>


#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "NDK_TEST", __VA_ARGS__)

int StartMainServer();

#endif
