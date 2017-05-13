#pragma once
#include <functional>
#include <vector>
#include "lazy_core.hpp"

namespace lzy {

	template <typename T> class vector : public std::vector<T>, public LZCORE<T> {

	public:
		/*
		* コンストラクタ
		*/
		vector(std::size_t size)
			: std::vector<T>(size)
		{
			/*
			*親クラスを生成するだけ
			*/
		}

		vector()
		{
			/*
			*オブジェクト生成のみ
			*/
		}


		void for_each(std::function<void(T &)> function) {
			unsigned int size = this->size();
			for (unsigned int i = 0; i < size; ++i) {
				function(this->at(i));
			}
		}

		vector<T *> filter(std::function<bool(T)> function) {
			vector<T *> _filtering_vector;

			for_each([&](T & element) {
				if (function(element)) {
					_filtering_vector.push_back(&element);
				}
			});

			return _filtering_vector;
		}
	};

}