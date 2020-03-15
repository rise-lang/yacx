/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class yacx_HalfArg */

#ifndef _Included_yacx_HalfArg
#define _Included_yacx_HalfArg
#ifdef __cplusplus
extern "C" {
#endif
#undef yacx_HalfArg_SIZE_BYTES
#define yacx_HalfArg_SIZE_BYTES 2LL
/*
 * Class:     yacx_HalfArg
 * Method:    createValue
 * Signature: (F)Lyacx/KernelArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_HalfArg_createValue
  (JNIEnv *, jclass, jfloat);

/*
 * Class:     yacx_HalfArg
 * Method:    createInternal
 * Signature: ([FZ)Lyacx/HalfArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_HalfArg_createInternal
  (JNIEnv *, jclass, jfloatArray, jboolean);

/*
 * Class:     yacx_HalfArg
 * Method:    asFloatArray
 * Signature: ()[F
 */
JNIEXPORT jfloatArray JNICALL Java_yacx_HalfArg_asFloatArray
  (JNIEnv *, jobject);

/*
 * Class:     yacx_HalfArg
 * Method:    asFloatArg
 * Signature: ()Lyacx/FloatArg;
 */
JNIEXPORT jobject JNICALL Java_yacx_HalfArg_asFloatArg
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
