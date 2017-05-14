#pragma once
#include <functional>
#include <vector>
#include "lazy_core.hpp"

namespace lzy {

	template <class T> class vector : public std::vector<T>, public LZCORE<T> {

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

		template <class _mapTo_t>
		vector<_mapTo_t> mapTo(std::function<_mapTo_t(T)> map_function) {
			vector<_mapTo_t> _mapping_vector;

			for_each([&](T & _element) {
				_mapping_vector.push_back(map_function(_element));
			});

			return _mapping_vector;
		}
	};

}