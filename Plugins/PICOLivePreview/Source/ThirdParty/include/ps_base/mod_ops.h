#pragma once
/*
 * Note(by Alan Duan): Get these codes from Webrtc.
 *                     Change namespace define and debug check function.
 */

#include <algorithm>
#include <type_traits>

namespace ps_base {
template <unsigned long M>                                    // NOLINT
inline unsigned long Add(unsigned long a, unsigned long b) {  // NOLINT
  unsigned long t = M - b % M;                                // NOLINT
  unsigned long res = a - t;                                  // NOLINT
  if (t > a) return res + M;
  return res;
}

template <unsigned long M>                                         // NOLINT
inline unsigned long Subtract(unsigned long a, unsigned long b) {  // NOLINT
  unsigned long sub = b % M;                                       // NOLINT
  if (a < sub) return M - (sub - a);
  return a - sub;
}

// Calculates the forward difference between two wrapping numbers.
//
// Example:
// uint8_t x = 253;
// uint8_t y = 2;
//
// ForwardDiff(x, y) == 5
//
//   252   253   254   255    0     1     2     3
// #################################################
// |     |  x  |     |     |     |     |  y  |     |
// #################################################
//          |----->----->----->----->----->
//
// ForwardDiff(y, x) == 251
//
//   252   253   254   255    0     1     2     3
// #################################################
// |     |  x  |     |     |     |     |  y  |     |
// #################################################
// -->----->                              |----->---
//
// If M > 0 then wrapping occurs at M, if M == 0 then wrapping occurs at the
// largest value representable by T.
template <typename T, T M>
inline typename std::enable_if<(M > 0), T>::type ForwardDiff(T a, T b) {
  static_assert(std::is_unsigned<T>::value,
                "Type must be an unsigned integer.");
  return a <= b ? b - a : M - (a - b);
}

template <typename T, T M>
inline typename std::enable_if<(M == 0), T>::type ForwardDiff(T a, T b) {
  static_assert(std::is_unsigned<T>::value,
                "Type must be an unsigned integer.");
  return b - a;
}

template <typename T>
inline T ForwardDiff(T a, T b) {
  return ForwardDiff<T, 0>(a, b);
}

// Calculates the reverse difference between two wrapping numbers.
//
// Example:
// uint8_t x = 253;
// uint8_t y = 2;
//
// ReverseDiff(y, x) == 5
//
//   252   253   254   255    0     1     2     3
// #################################################
// |     |  x  |     |     |     |     |  y  |     |
// #################################################
//          <-----<-----<-----<-----<-----|
//
// ReverseDiff(x, y) == 251
//
//   252   253   254   255    0     1     2     3
// #################################################
// |     |  x  |     |     |     |     |  y  |     |
// #################################################
// ---<-----|                             |<-----<--
//
// If M > 0 then wrapping occurs at M, if M == 0 then wrapping occurs at the
// largest value representable by T.
template <typename T, T M>
inline typename std::enable_if<(M > 0), T>::type ReverseDiff(T a, T b) {
  static_assert(std::is_unsigned<T>::value,
                "Type must be an unsigned integer.");
  return b <= a ? a - b : M - (b - a);
}

template <typename T, T M>
inline typename std::enable_if<(M == 0), T>::type ReverseDiff(T a, T b) {
  static_assert(std::is_unsigned<T>::value,
                "Type must be an unsigned integer.");
  return a - b;
}

template <typename T>
inline T ReverseDiff(T a, T b) {
  return ReverseDiff<T, 0>(a, b);
}

// Calculates the minimum distance between to wrapping numbers.
//
// The minimum distance is defined as min(ForwardDiff(a, b), ReverseDiff(a, b))
template <typename T, T M = 0>
inline T MinDiff(T a, T b) {
  static_assert(std::is_unsigned<T>::value,
                "Type must be an unsigned integer.");
  return (std::min)(ForwardDiff<T, M>(a, b), ReverseDiff<T, M>(a, b));
}

}  // namespace ps_base
