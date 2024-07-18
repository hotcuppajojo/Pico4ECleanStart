#pragma once
#include <stdint.h>

#include "ps_base/ps_exports.h"
#include "ps_base/transport/data_buffer.h"

namespace ps_base {

enum class VideoCodecType {
  kUndefined = 0,
  kH264,
  kH265,
  kAV1,
};

enum class VideoCodecMode {
  kUndefined = 0,
  kSync,
  kAsync,
};
//bitrate control mode
enum class VideoCodecBitRateMode {
  BITRATE_MODE_CQ = 0, //Constant quality mode
  BITRATE_MODE_VBR,    //Variable bitrate mode
  BITRATE_MODE_CBR,    //Constant bitrate mode
};

class PS_BASE_API VideoCodecConfig {
 public:
  VideoCodecConfig() = default;
  ~VideoCodecConfig() = default;
  VideoCodecConfig(const VideoCodecConfig& other);

  VideoCodecType GetCodecType_() const;
  void SetCodecType_(VideoCodecType type);

  VideoCodecMode GetCodecMode_() const;
  void SetCodecMode_(VideoCodecMode mode);

  int32_t GetWidth_() const;
  void SetWidth_(int32_t width);

  int32_t GetHeight_() const;
  void SetHeight_(int32_t height);

  int32_t GetBitrate_() const;
  void SetBitrate_(int32_t bitrate);

  int32_t GetFps_() const;
  void SetFps_(int32_t fps);

  int32_t GetColorFormat() const;
  void SetColorFormat(int32_t color_format);

  VideoCodecBitRateMode GetBitRateMode_() const;
  void SetBitRateMode_(VideoCodecBitRateMode mode);

  VideoCodecType codec_type() const;
  VideoCodecType& codec_type();

  int32_t width() const;
  int32_t& width();

  int32_t height() const;
  int32_t& height();

  int32_t bitrate() const;
  int32_t& bitrate();

  int32_t fps() const;
  int32_t& fps();

  int32_t color_format() const;
  int32_t& color_format();

  VideoCodecBitRateMode bitrate_mode() const;
  VideoCodecBitRateMode& bitrate_mode();

  VideoCodecConfig& operator=(const VideoCodecConfig& other);
  bool operator==(const VideoCodecConfig& other) const;
  ps_base::DataBuffer ToString() const;

 private:
  VideoCodecType codec_type_ = VideoCodecType::kUndefined;
  VideoCodecMode codec_mode_ = VideoCodecMode::kUndefined;
  int32_t width_ = 0;
  int32_t height_ = 0;
  int32_t bitrate_ = 0;
  int32_t fps_ = 0;
  int32_t color_format_ = 0;
  VideoCodecBitRateMode bitrate_mode_ = VideoCodecBitRateMode::BITRATE_MODE_CBR;
};
}  // namespace ps_base
