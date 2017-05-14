#include "lzy_shorter.hpp"

void for_times(u64_t times, fn<void(int count)> loop_function) {
	while (times--) {
		loop_function(times);
	}
}