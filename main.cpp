#include <jni.h>
#include "my_includes.h"
#include "Main.h"

extern "C" JNIEXPORT void JNICALL Java_Main_sortArray(JNIEnv *env, jobject obj, jintArray array) {
    // Get the length of the array from Java
    jsize length = env->GetArrayLength(array);
    
    // Create a C++ vector to hold the elements
    std::vector<int> vec(length);

    // Copy the elements from the Java array to the C++ vector
    env->GetIntArrayRegion(array, 0, length, &vec[0]);

    // Sort the vector in ascending order using std::sort
    std::sort(vec.begin(), vec.end());

    // Copy the sorted vector back to the Java array
    env->SetIntArrayRegion(array, 0, length, &vec[0]);
}