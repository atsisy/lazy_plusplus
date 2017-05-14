#ifndef _LZY_SHORTER_HPP
#define _LZY_SHORTER_HPP

#include <functional>
#include "lz_vector.hpp"

template <class T>
using lzyVec = lzy::vector<T>;

template <typename T>
using fn = std::function<T>;

using i8_t = char;
using u8_t = unsigned char;
using i16_t = short;
using u16_t = unsigned short;
using i32_t = int;
using u32_t = unsigned int;
using i64_t = long long;
using u64_t = unsigned long long;

#endif