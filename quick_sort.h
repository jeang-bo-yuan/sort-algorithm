#include <vector>

#define SORTING_FUNC(A) quick_sort(A.begin(), A.end())
#define NAME "quick sort"

// 在[start, end)取一個pivot，並將陣列分成「小於等於pivot」和「大於pivot」這兩部分
// 回傳值為pivot的位置
std::vector<int>::iterator partition(std::vector<int>::iterator start, 
	                                 std::vector<int>::iterator end) {
	size_t len = end - start;
	if (len <= 1) return start;

	int pivot = *(end - 1); // 取最後一個元素當pivot

	auto larger_start = start; // [larger_start, it) 都是比pivot大的部分
	for (auto it = start; it != end; ++it) {
		if (*it <= pivot) {
			std::swap(*larger_start, *it); // 和「大於pivot」中的第一個元素交換
			++larger_start;
		}
	}

	// 因為it最後會指到pivot所在位置，並且*it <= pivot為真
	// 所以pivot自然而然地被放到「大於pivot的部分」的前面一位
	return larger_start - 1;
}

// 升冪排序
// 對vector中的[start, end)做排序，參數的意義如同std::sort
void quick_sort(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	size_t len = end - start;
	if (len <= 1) return;

	auto pivot_it = partition(start, end);
	quick_sort(start, pivot_it);   // 小於等於pivot的部分
	quick_sort(pivot_it + 1, end); // 大於pivot的部分
}
