/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 *
 * @brief The implementation of the KthLargest class, which is used to find the
 * kth largest element in a stream.
 *
 * The KthLargest class provides a constructor, KthLargest, that takes an
 * integer k and a vector of integers as input. The class has a method, add,
 * that takes an integer value and returns the kth largest element in the
 * stream. The method uses a priority queue to store the k largest elements in
 * the stream. If the size of the priority queue exceeds k, the method removes
 * the smallest element from the queue. The method returns the top element of
 * the priority queue.
 *
 * Algorithm Complexity:
 * - The KthLargest constructor has a time complexity of O(n*log(k)), where n is
 * the number of elements in the input vector and k is the value of k.
 * - The add method has a time complexity of O(log(k)).
 * - The space complexity of the class is O(k), where k is the value of k.
 */

// @lc code=start
class KthLargest {
	priority_queue<int, vector<int>, greater<int>> pq;
	int size;

   public:
	KthLargest(int k, vector<int>& nums) {
		size = k;

		// Add the elements to the priority queue.
		for (auto i : nums) {
			add(i);
		}

		return;
	}

	int add(int val) {
		pq.push(val);
		// If the size of the priority queue exceeds k, remove the smallest
		// element.
		if (pq.size() > size)
			pq.pop();

		return pq.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
