#include <jni.h>
#include <string.h>
#include <assert.h>

#include "NDKUtils.h"
#include "main.h"

JNIEXPORT void JNICALL StartGoaheadServer(JNIEnv *env, jobject obj) {
	LOGD("jni.StartGoaheadServer");  
	StartMainServer();

}

static JNINativeMethod methods[] = {
        {"StartGoaheadServer", "()V", (void *) StartGoaheadServer},
};

static int registerNativeMethods(JNIEnv *env, const char *className, JNINativeMethod *gMethods, int numMethods) {
    jclass clazz;
    clazz = (*env)->FindClass(env, className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if ((*env)->RegisterNatives(env, clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

static int registerNatives(JNIEnv *env) {
    const char *className = "com/jni/libgo/NDKgoahead"; 
    return registerNativeMethods(env, className, methods, sizeof(methods) / sizeof(methods[0]));
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
    //LOGD("-------------JNI_OnLoad into.--------\n");
    JNIEnv* env = NULL;
    jint result = -1;

    if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK){
        return -1;
    }
    assert(env != NULL);

    if (!registerNatives(env)) {
        return -1;
    }

    return JNI_VERSION_1_4;
}
