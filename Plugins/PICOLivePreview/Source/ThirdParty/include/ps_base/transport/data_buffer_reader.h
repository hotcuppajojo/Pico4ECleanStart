#pragma once
#include <stdint.h>

#include <memory>

#include "ps_base/ps_exports.h"
#include "ps_base/transport/data_buffer.h"

namespace ps_base {
class PS_BASE_API DataBufferReader {
 public:
  DataBufferReader(const uint8_t* buffer, size_t length, size_t beg = 0);

  size_t Read(uint8_t* buffer, size_t buffer_size, bool change_offset = true);
  size_t Read(DataBuffer& buffer, bool change_offset = true);
  size_t Read(DataBuffer& buffer, size_t size, bool change_offset = true);
  size_t Offset_() const;
  size_t Length_() const;
  const uint8_t* ReadPtr_() const;
  size_t RemainingLength_() const;
  bool Valid_() const;
  void Reset();

 private:
  bool IsConsistent() const;
  void Clear();

 private:
  const uint8_t* buffer_ = nullptr;
  size_t beg_ = 0;
  size_t length_ = 0;
  size_t offset_ = 0;
};
}  // namespace ps_base