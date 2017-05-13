#pragma once
#include <functional>
#include <vector>
#include "lazy_core.hpp"

namespace lzy {
	template <typename T> class vector : public std::vector<T>, public LZCORE<T> {
	public:
		void for_each(std::function<void(T)> function) {
			unsigned int size = this->size();
			for (unsigned int i = 0; i < size; ++i) {
				function(this->at(i));
			}
		}
	};
}