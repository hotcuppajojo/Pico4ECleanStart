#pragma once

#ifdef _WIN32
#elif defined(__ANDROID__)
#include <android/binder_ibinder_jni.h>
#include <jni.h>
#elif defined(__MACH__)
#endif

namespace ps_common {

#ifdef _WIN32
struct PlatformBindingWindows {};
#elif defined(__ANDROID__)
struct PlatformBindingAndroid {
  JNIEnv* java_env = nullptr;
  AIBinder* binder = nullptr;
};
#elif defined(__MACH__)
struct PlatformBindingMac {};
#endif

struct PlatformBinding {
#ifdef _WIN32
  PlatformBindingWindows windows_binding;
#elif defined(__ANDROID__)
  PlatformBindingAndroid android_binding;
#elif defined(__MACH__)
  PlatformBindingMac mac_binding;
#endif
};
}  // namespace ps_common