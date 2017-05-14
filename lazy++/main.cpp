#include <iostream>
#include "lazy++.hpp"
#include <string>

fn<void()> outer() {
	static int x = 0;

	return [&] { 
		std::cout << x << std::endl;
		x++;
	};
}

int main() {
	lzyVec<int> vec;
	for (int i = 0; i < 100; ++i) {
		vec.push_back(i);
	}

	for_times(10, [](int count) {std::cout << count << std::endl; });

	lzy::processing_time timer([&] {

		vec.for_each([&](auto f) {
			f += 10;
		});

		vec.filter([&](int elem) {
			return !(elem % 3);
		}).for_each([&](int *elem) {
			*elem = 0;
		});

		auto n_vec = vec.mapTo<std::string>([&](auto elem) {
			return std::to_string(elem);
		});

		n_vec.for_each([&](auto str) {
			//std::cout << str << std::endl;
		});

		auto nn_vec = n_vec.deepCopy(n_vec.begin(), n_vec.end());

		nn_vec.for_each([](auto str) {
			std::cout << str << std::endl;
		});

	});
	timer.start();

	std::cout << timer.getResult() << std::endl;
/*
	auto b = outer();
	b();
	b();
	b();

	auto f = outer();
	f();
	f();
	f();
*/


}