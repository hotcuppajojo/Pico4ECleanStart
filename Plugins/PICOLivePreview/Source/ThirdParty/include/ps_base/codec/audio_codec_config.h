#pragma once

#include <cstdint>

#include "ps_base/ps_exports.h"
#include "ps_base/transport/data_buffer.h"
namespace ps_base {

enum class AudioCodecType {
  kUndefinedAudioCodecType = 0,
  kPcm,
};

class PS_BASE_API AudioCodecConfig {
 public:
  AudioCodecConfig() = default;
  ~AudioCodecConfig() = default;
  AudioCodecConfig(const AudioCodecConfig& other);

  [[nodiscard]] AudioCodecType GetCodecType_() const;
  void SetCodecType_(AudioCodecType type);

  [[nodiscard]] uint32_t GetChannels_() const;
  void SetChannels_(uint32_t channels);

  [[nodiscard]] uint32_t GetSampleDepth_() const;
  void SetSampleDepth_(uint32_t depth);

  [[nodiscard]] uint32_t GetSampleRate_() const;
  void SetSampleRate_(uint32_t rate);

  [[nodiscard]] AudioCodecType codec_type() const;
  AudioCodecType& codec_type();

  [[nodiscard]] uint32_t channels() const;
  uint32_t& channels();

  [[nodiscard]] uint32_t sample_depth() const;
  uint32_t& sample_depth();

  [[nodiscard]] uint32_t sample_rate() const;
  uint32_t& sample_rate();

  AudioCodecConfig& operator=(const AudioCodecConfig& other);
  bool operator==(const AudioCodecConfig& other);
  bool operator!=(const AudioCodecConfig& other);
  [[nodiscard]] ps_base::DataBuffer ToString() const;

 private:
  AudioCodecType codec_type_ = AudioCodecType::kUndefinedAudioCodecType;
  uint32_t channels_ = 0;
  uint32_t sample_depth_ = 0;
  uint32_t sample_rate_ = 0;
};
}  // namespace ps_base
