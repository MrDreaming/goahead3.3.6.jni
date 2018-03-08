#include <jni.h>

#ifndef _NDK_UTILS_
#define _NDK_UTILS_
#ifdef __cplusplus
extern "C" {
#endif

//JNIEXPORT jstring JNICALL Java_demo_jnidemo_NDKUtils_getVipString(JNIEnv *, jobject);

//JNIEXPORT jstring JNICALL Java_demo_jnidemo_NDKUtils_staticGenerateKey(JNIEnv *, jobject, jstring);

JNIEXPORT void JNICALL StartGoaheadServer(JNIEnv *env, jobject obj);

#ifdef __cplusplus
}
#endif
#endif
