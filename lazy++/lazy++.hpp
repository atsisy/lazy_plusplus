#ifndef _LAZY_PLUS_PLUS_HPP
#define _LAZY_PLUS_PLUS_HPP

#include "lzy_shorter.hpp"
#include "lz_vector.hpp"
#include "p_time.hpp"

void for_times(u64_t times, fn<void(int count)> loop_function);

void print(std::string str);
void print(const char *str);
void print(int number);
void ln();

#endif