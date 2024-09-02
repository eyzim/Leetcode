/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * @brief The implementation of the Solution class, which is used to find the
 * kth largest element in an array. Note that we are not allowed to use the sort
 * method in this case.
 *
 * The Solution class provides a method, findKthLargest, that takes a vector of
 * integers and an integer value k as input and returns an integer value
 * representing the kth largest element in the array. The method uses a priority
 * queue to store the k largest elements in the array. It iterates over the
 * input array and pushes each element into the priority queue. If the size of
 * the priority queue exceeds k, the method pops the smallest element from the
 * queue. Finally, the method returns the top element of the priority queue,
 * which is the kth largest element in the array.
 *
 * Algorithm Complexity:
 * - The findKthLargest method has a time complexity of O(n*log(k)), where n is
 * the number of elements in the input array.
 * - The space complexity of the method is O(k), where k is the value of the
 * input parameter k.
 */

// @lc code=start
class Solution {
   public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> pq;

		for (auto i : nums) {
			pq.push(i);
			if (pq.size() > k) {
				pq.pop();
			}
		}

		return pq.top();
	}
};
// @lc code=end
