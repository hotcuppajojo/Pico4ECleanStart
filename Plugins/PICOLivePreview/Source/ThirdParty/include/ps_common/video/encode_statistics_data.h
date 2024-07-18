#pragma once

#include <stdint.h>

#include "ps_common/ps_exports.h"

namespace ps_common {
class PS_COMMON_API EncodeStatisticsData {
 public:
  int64_t GetEyeIndex_() const;
  void SetEyeIndex_(int64_t eye_index);

  float GetEyeTimedelay_(int64_t index) const;
  void SetEyeTimedelay_(int64_t index, float eye_timedelay);

  void Reset();

 private:
  int64_t eye_index_;
  float eye_timedelay_[2] = {0, 0};
};
}  // namespace ps_common
