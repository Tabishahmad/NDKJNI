#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_app_ndktest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_app_ndktest_MainActivity_apiKey(JNIEnv *env, jobject object) {

std::string api_key = "your_api_key";

return env->NewStringUTF(api_key.c_str());
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_app_ndktest_MainActivity_passparam(JNIEnv *env, jobject object, jstring jstr) {
    const char* str = env->GetStringUTFChars(jstr, nullptr);
    if (str != nullptr) {
        // Use the string in your C++ code as needed
        // For example, you can print the string:
        printf("Received string: %s\n", str);
        // Don't forget to release the string to avoid memory leaks
        env->ReleaseStringUTFChars(jstr, str);
    }
}
extern "C" JNIEXPORT void JNICALL
Java_com_app_ndktest_MainActivity_callKotlinMethod(JNIEnv* env, jobject /* this */) {
    // Obtain the class and method IDs of the Kotlin method you want to call
    jclass kotlinClass = env->FindClass("com/app/ndktest/MainActivity");
    jmethodID kotlinMethod = env->GetStaticMethodID(kotlinClass, "yourKotlinMethod", "()V");

    // Call the Kotlin method
    env->CallStaticVoidMethod(kotlinClass, kotlinMethod);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_your_package_name_MyClass_reverseString(JNIEnv* env, jobject /* this */, jstring jstr) {
    const char* str = env->GetStringUTFChars(jstr, nullptr);
    if (str == nullptr) {
        return nullptr;
    }

    // Reverse the string
    int length = env->GetStringUTFLength(jstr);
    char reversedStr[length + 1];
    for (int i = 0; i < length; i++) {
        reversedStr[i] = str[length - i - 1];
    }
    reversedStr[length] = '\0';

    // Release the string
    env->ReleaseStringUTFChars(jstr, str);

    // Return the reversed string as a new Java string
    return env->NewStringUTF(reversedStr);
}