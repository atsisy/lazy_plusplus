#include <iostream>
#include <chrono>
#include "lz_vector.hpp"
#include "cmdline_wiz.hpp"

int main() {
	lzy::vector<int> vec;
	for (int i = 0; i < 100000; ++i) {
		vec.push_back(i);
	}

	std::chrono::system_clock::time_point  start, end; // 型は auto で可
	start = std::chrono::system_clock::now(); // 計測開始時間

	vec.for_each([&](auto f) {
		f += 10;
	});

	end = std::chrono::system_clock::now();  // 計測終了時間
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl; //処理に要した時間をミリ秒に変換

	CommandLineWiz wiz("git add");

	std::cout << wiz.At(0) << std::endl;

}