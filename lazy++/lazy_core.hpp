#pragma once

namespace lzy {
	template <typename T> class LZCORE {
	public:
		virtual void for_each(std::function<void(T &)> function) = 0;
	};
}