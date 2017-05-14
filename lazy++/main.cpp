#include <iostream>
#include <chrono>
#include "lz_vector.hpp"
#include "cmdline_wiz.hpp"
#include "p_time.hpp"

int main() {
	lzy::vector<int> vec;
	for (int i = 0; i < 100; ++i) {
		vec.push_back(i);
	}

	lzy::processing_time timer([&]() {

		vec.for_each([&](auto f) {
			f += 10;
		});

		vec.filter([&](int elem) {
			return !(elem % 3);
		}).for_each([&](int *elem) {
			*elem = 0;
		});

		vec.for_each([&](auto elem) {
			std::cout << elem << std::endl;
		});

	});
	timer.start();

	std::cout << timer.getResult() << std::endl;

	
	CommandLineWiz wiz("git add");

	std::cout << wiz.At(0) << std::endl;

}