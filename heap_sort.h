#include <vector>
#include <algorithm>

#define SORTING_FUNC heap_sort
#define NAME "heap sort"

namespace Heap {
	// 父節點
	inline size_t parent(size_t i) { return i ? static_cast<size_t>(ceil(i / 2.0)) - 1 : 0; }
	// 左子樹
	inline size_t left(size_t i) { return (i << 1) + 1; }
	// 右子樹
	inline size_t right(size_t i) { return (i << 1) + 2; }

	/// //////////////////////////////////////////////////////////////////////////
	/// @param heap - 儲存heap的陣列
	/// @param heap_size - 只有 [0, heap_size) 的區間是heap
	/// @param i - 對哪個節點做 heapify
	/// 
	/// @pre 假設 left(i) 和 right(i) 是 max heap
	/// @post 將heap的第i項向下移（如有必要的話），使以i節點為根的子樹成為max heap
	/// 
	void max_heapify(std::vector<int>& heap, const size_t heap_size, size_t i) {
		while (true) {
			size_t L = left(i), R = right(i);

			// i, L, R 哪個節點的值最大
			size_t max = i;
			if (L < heap_size && heap[L] > heap[max]) max = L;
			if (R < heap_size && heap[R] > heap[max]) max = R;

			// 已經是max heap了
			if (max == i) return;

			// 否則將max節點的值往上移，並對max節點做max_heapify
			std::swap(heap[i], heap[max]);
			i = max;
		}
	}

	/// 使heap成為真正的max heap
	/// @param[in,out] heap - 儲存heap的陣列
	void make_max_heap(std::vector<int>& heap) {
		// 從最後一個節點的父節點開始，對每個節點呼叫max_heapify
		// 迴圈終止條件為i == -1，而(size_t)0 - 1 == SIZE_MAX
		for (size_t i = parent(heap.size() - 1); i != SIZE_MAX; --i) {
			max_heapify(heap, heap.size(), i);
		}
	}
}

// 升冪排序
void heap_sort(std::vector<int>& A) {
	if (A.size() <= 1) return;

	Heap::make_max_heap(A);
	
	for (size_t heap_size = A.size(); heap_size > 1; ) {
		// 將heap最上方的元素（最大值）取出來放到heap最後面
		// 交換後 [heap_size - 1, A.size()) 會是已排序好的
		std::swap(A[0], A[heap_size - 1]);

		--heap_size;
		Heap::max_heapify(A, heap_size, 0);
	}
}
