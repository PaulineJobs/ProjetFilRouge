
#include <string.h>
#include "com_abcd_jni_HelloWorldJNI.h"

JNIEXPORT void JNICALL Java_com_abcd_jni_HelloWorldJNI_sayHello
  (JNIEnv* env, jobject thisObject) {
    //std::cout << "Hello from C++ !!" << std::endl;
    printf("Hello world\n");
}

JNIEXPORT jlong JNICALL Java_com_abcd_jni_HelloWorldJNI_sumIntegers
  (JNIEnv* env, jobject thisObject, jint first, jint second) {
    //std::cout << "C++: The numbers received are : " << first << " and " << second << std::endl;
    printf("The numbers received are : %d and %d \n",first,second);
    return (long)first + (long)second;
}

JNIEXPORT jstring JNICALL Java_com_abcd_jni_HelloWorldJNI_sayHelloToMe
  (JNIEnv* env, jobject thisObject, jstring name, jboolean isFemale) {
    const char* nameCharPointer = (*env)->GetStringUTFChars(env, name, NULL);
    char* title;
    char fullName[100];


    if(isFemale) {
        title = "Ms. ";
    }
    else {
        title = "Mr. ";
    }

    strcpy(fullName,title);
    strcat(fullName,nameCharPointer);
    printf("FullName %s \n",fullName);
    return (*env)->NewStringUTF(env, fullName);
}

