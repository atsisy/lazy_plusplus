#ifndef _P_TIME_HPP
#define _P_TIME_HPP

#include <functional>
#include <chrono>

namespace lzy {

	class processing_time {
	private:
		std::function<void(void)> process;
		double result;

	public:
		processing_time(std::function<void(void)> function);
		double start(void);
		double getResult(void);

	};

}

#endif