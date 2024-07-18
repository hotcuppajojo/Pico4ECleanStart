#pragma once
#include <stdint.h>

#include "ps_common/ps_exports.h"
#include "ps_common/quaternion.h"
#include "ps_common/vector.h"

namespace ps_common {
class PS_COMMON_API DriverSharedImages {
 public:
  DriverSharedImages() = default;
  ~DriverSharedImages() = default;

  DriverSharedImages(const DriverSharedImages& other) = default;
  DriverSharedImages& operator=(const DriverSharedImages& other) = default;
  bool operator==(const DriverSharedImages& other);
  bool operator!=(const DriverSharedImages& other);
  void Reset();
  [[nodiscard]] ps_base::DataBuffer ToString() const;

  [[nodiscard]] void* shared_handle(int index) const;
  void*& mutable_shared_handle(int index);

  [[nodiscard]] const Vector& position() const;
  Vector& mutable_position();

  [[nodiscard]] const Quaternion& rotation() const;
  Quaternion& mutable_rotation();

  [[nodiscard]] uint64_t timestamp() const;
  uint64_t& mutable_timestamp();

 private:
  void* shared_handle_[2] = {nullptr};
  uint64_t timestamp_ = 0;
  Vector position_;
  Quaternion rotation_;
};
}  // namespace ps_common