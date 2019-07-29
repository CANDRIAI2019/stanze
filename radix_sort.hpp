#ifndef _RADIX_SORT_HPP_
#define _RADIX_SORT_HPP_

#include <type_traits>
#include <algorithm>

template<class Iterator, size_t maxNumber, typename = std::enable_if_t<std::is_integral_v<typename Iterator::value_type>>>
void radix_sort(Iterator begin, Iterator end) {
	std::vector<typename Iterator::value_type> buckets[16];

	auto getJthDigit = [](typename Iterator::value_type x, size_t j) constexpr {
		x >>= j*4;
		return ((x >> 4) << 4) ^ x;
	};

	auto getNumDigits = [](typename Iterator::value_type x) constexpr {
		size_t numDigits = 0;
		while (x != 0) {
			x >>= 4;
			++numDigits;
		}
		return numDigits;
	};

	constexpr size_t numDigits = getNumDigits(maxNumber);
	for(size_t j = 0; j != numDigits; ++j) {
		for(auto numIter = begin; numIter != end; ++numIter) {
			buckets[getJthDigit(*numIter, j)].push_back(*numIter);
		}

		size_t i = 0;
		for(auto&& bucket : buckets) {
			for(auto num : bucket) {
				begin[i] = num;
				++i; 
			}
			bucket.clear();
		}
	}
}

#endif // _RADIX_SORT_HPP_
