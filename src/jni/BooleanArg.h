/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class BooleanArg */

#ifndef _Included_BooleanArg
#define _Included_BooleanArg
#ifdef __cplusplus
extern "C" {
#endif
#undef BooleanArg_SIZE_BYTES
#define BooleanArg_SIZE_BYTES 1L
/*
 * Class:     BooleanArg
 * Method:    createValue
 * Signature: (Z)LKernelArg;
 */
JNIEXPORT jobject JNICALL Java_BooleanArg_createValue
  (JNIEnv *, jclass, jboolean);

/*
 * Class:     BooleanArg
 * Method:    create
 * Signature: (LBooleanArg;Z)LBooleanArg;
 */
JNIEXPORT jobject JNICALL Java_BooleanArg_create
  (JNIEnv *, jclass, jobject, jboolean);

/*
 * Class:     BooleanArg
 * Method:    createInternal
 * Signature: ([ZZ)LBooleanArg;
 */
JNIEXPORT jobject JNICALL Java_BooleanArg_createInternal
  (JNIEnv *, jclass, jbooleanArray, jboolean);

/*
 * Class:     BooleanArg
 * Method:    createOutputInternal
 * Signature: (I)LBooleanArg;
 */
JNIEXPORT jobject JNICALL Java_BooleanArg_createOutputInternal
  (JNIEnv *, jclass, jint);

/*
 * Class:     BooleanArg
 * Method:    asBooleanArray
 * Signature: ()[Z
 */
JNIEXPORT jbooleanArray JNICALL Java_BooleanArg_asBooleanArray
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
