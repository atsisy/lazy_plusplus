#include "lzy_shorter.hpp"
#include <stdio.h>

void for_times(u64_t times, fn<void(int count)> loop_function) {
	while (times--) {
		loop_function(times);
	}
}

void print(std::string str) {
	printf("%s", str.data());
}

void print(const char *str) {
	printf("%s", str);
}

void print(int number) {
	printf("%d", number);
}

void ln() {
	printf("\n");
}