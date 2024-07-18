#pragma once

#include <cstdint>

#include "platform.h"
#include "ps_base/codec/video_codec_config.h"
#include "ps_common/device_type.h"
#include "ps_common/graphics.h"
#include "ps_common/platform.h"
#include "ps_common/stream/connection_config.h"

namespace ps_common {
enum class ListOperationType {
  kUndefined = -1,
  kAdd = 0,
  kRemove = 1,
  kUpdate = 2
};
struct ExternalDeviceInfo {
  ConnectionType connection_type = ConnectionType::kUndefined;
  char device_id[256] = {0};
  char device_name[256] = {0};
  char device_platform[256] = {0};
};
struct HMDDeviceInfo {
  ConnectionType connection_type = ConnectionType::kUndefined;
  char device_id[256] = {0};
  char device_name[256] = {0};
  char device_platform[256] = {0};
};
enum class StreamingContentType {
  kUndefined = -1,
  kSteamVRApp = 0,
  kDesktop = 1,
};
enum class DisplayType {
  kUndefined = -1,
  kHardwareDisplay = 0,
  kVirtualDisplay = 1
};
struct StreamingContentInfo {
  StreamingContentType content_type = StreamingContentType::kUndefined;

  DisplayType display_type = DisplayType::kUndefined;
  char display_name[256] = {'\0'};
  int32_t display_width = 0;
  int32_t display_height = 0;
  int32_t refresh_rate_khz = 0;
  int32_t display_index = 0;

  char app_url[256] = {'\0'};
  char app_name[256] = {'\0'};
  char app_poster_url[1024 * 8] = {'\0'};
};
struct StreamingContentListItem {
  ListOperationType operation_type = ListOperationType::kUndefined;
  StreamingContentInfo content_info;
};
enum class StreamingContentStateType {
  kUndefined = -1,
  kSet = 0,
  kLaunched = 1,
  kRefused = 2,
  kFailed = 3
};
struct StreamingContentState {
  StreamingContentStateType state_type = StreamingContentStateType::kUndefined;
  StreamingContentInfo content_info;
  char description[1024]{};
};

enum class TouchEventType {
  kUndefined = -1,
  kDown = 0,
  kUp = 1,
  kMove = 2,
  kHover = 3
};

struct TouchEvent {
  uint64_t timestamp = 0;
  TouchEventType event_type = TouchEventType::kUndefined;
  float pos_x = 0.f;
  float pos_y = 0.f;
};

enum class StreamingStateType {
  kUndefined = 0,
  kLaunching = 1,
  kRunning = 2,
  kPaused = 3,
  kFinished = 4
};
struct StreamingConfig {
  StreamingContentType streaming_content_type =
      StreamingContentType::kUndefined;
  ps_common::GraphicsBinding graphics_binding;
  ps_common::PlatformBinding platform_binding{};
  uint32_t width = 0;
  uint32_t height = 0;
  uint32_t frame_rate = 0;
  uint32_t bitrate_mbps = 0;
  bool auto_adapt_bitrate = false;
  ps_base::VideoCodecType video_codec_type =
      ps_base::VideoCodecType::kUndefined;
  bool enable_sharpening = false;
  bool enable_interpolated_frame = false;
};
struct StreamingState {
  StreamingStateType state_type = StreamingStateType::kUndefined;
  StreamingConfig streaming_config;
};
struct StreamingStatistics {
  uint32_t render_lag_ms = 0;
  int32_t signal_strength = 0;
};
struct DeviceBatteryState {
  DeviceType device_type = DeviceType::kUndefined;
  SideType side_type = SideType::kUndefined;
  bool active = false;
  int percentage = 0;
};
enum class PerformancePanelStyle { kUndefined = 0, kSimple = 1, kDetail = 2 };
struct StreamingRealtimeConfig {
  PerformancePanelStyle performance_panel_style =
      PerformancePanelStyle::kUndefined;
};
struct AccountLoginInfo {
  bool login_flag = false;
  char user_id[1024] = {'\0'};
  bool enable_usb_auto_connect = false;
  bool enable_network_auto_connect = false;
  ExternalDeviceInfo external_device_info;
};
struct SteamVRAppInfo {
  char app_key[1024] = {0};
  char app_name[1024] = {0};
};
}  // namespace ps_common
