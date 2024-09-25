#include <vector>
#include <algorithm>

#define SORTING_FUNC(A) merge_sort(A.begin(), A.end())
#define NAME "merge sort"

// 升冪排序
// 對vector中的[start, end)做排序，參數的意義如同std::sort
void merge_sort(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	size_t len = end - start;
	if (len <= 1) return;

	auto middle = start + (len / 2);
	// 將原陣列拆成兩半[start, middle)和[middle, end)
	// 並分別對這兩個部分做merge sort
	merge_sort(start, middle);
	merge_sort(middle, end);

	// 接下來將排列好的兩陣列合併成一個陣列
	std::vector<int> merge_result; merge_result.reserve(len);
	auto i1 = start, i2 = middle;
	while (merge_result.size() < len) {
		// 如果 前半的陣列還有元素 且 (後半沒元素了 或 前半的陣列有比較小的值)
		if (i1 != middle && (i2 == end || *i1 <= *i2)) {
			merge_result.push_back(*i1);
			++i1;
		}
		else {
			merge_result.push_back(*i2);
			++i2;
		}
	}

	// copy back
	std::copy(merge_result.begin(), merge_result.end(), start);
}
