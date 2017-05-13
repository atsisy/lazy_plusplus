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


		void for_each(std::function<void(T)> function) {
			unsigned int size = this->size();
			for (unsigned int i = 0; i < size; ++i) {
				function(this->at(i));
			}
		}
	};

}