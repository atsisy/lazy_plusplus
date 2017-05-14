#include "p_time.hpp"

namespace lzy {
	
	processing_time::processing_time(std::function<void(void)> function) {
		process = function;
		result = 0;
	}
	
	double processing_time::start(void) {
		std::chrono::system_clock::time_point  start, end;
		start = std::chrono::system_clock::now();

		/*
		* ˆ—ŠJŽn
		*/
		this->process();

		end = std::chrono::system_clock::now();
		return (result = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
	}

	double processing_time::getResult(void) {
		return result;
	}
}