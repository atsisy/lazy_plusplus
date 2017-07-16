#include <iostream>
#include "lazy++.hpp"
#include <string>

fn<void()> outer() {
	static int x = 0;

	return [&] { 
		print(x); ln();
		x++;
	};
}

int main() {
	lzyVec<int> vec;
	for (int i = 0; i < 100; ++i) {
		vec.push_back(i);
	}

	for_times(10, [](int count) { print(count); ln(); });

	lzy::processing_time timer([&] {

		vec.for_each([&](auto f) {
			f += 10;
		});

		vec.filter([&](int elem) {
			return !(elem % 3);
		}).for_each([&](int & elem) {
			elem = 0;
		});

		vec.for_each([&](int v) { std::cout << v << std::endl; });

	});
	timer.start();

	print(timer.getResult());
	ln();

}