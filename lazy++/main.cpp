#include <iostream>
#include <chrono>
#include "lz_vector.hpp"
#include "cmdline_wiz.hpp"

int main() {
	lzy::vector<int> vec;
	for (int i = 0; i < 100000; ++i) {
		vec.push_back(i);
	}

	std::chrono::system_clock::time_point  start, end; // �^�� auto �ŉ�
	start = std::chrono::system_clock::now(); // �v���J�n����

	vec.for_each([&](auto f) {
		f += 10;
	});

	end = std::chrono::system_clock::now();  // �v���I������
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl; //�����ɗv�������Ԃ��~���b�ɕϊ�

	CommandLineWiz wiz("git add");

	std::cout << wiz.At(0) << std::endl;

}