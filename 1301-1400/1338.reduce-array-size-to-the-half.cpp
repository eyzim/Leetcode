/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 *
 * @brief The implementation of the Solution class, which is used to reduce the
 * size of the array to half.
 *
 * The Solution class provides a method, minSetSize, that takes a vector of
 * integers, arr, as input and returns the minimum size of the set that can be
 * removed to reduce the size of the array to half. First, it stores the
 * frequency of each element in the array in an unordered_map, mp. It then
 * creates a max heap, pq, to store the frequency of each element. It removes
 * the elements from the heap until the removed elements are greater than half
 * of the array size. Finally, it returns the number of times the elements were
 * removed.
 *
 * Algorithm Complexity:
 * - The minSetSize method has a time complexity of O(n log n), where n is the
 * number of elements in the array.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
class Solution {
   public:
	int minSetSize(vector<int>& arr) {
		// Store the frequency of each element in the array
		unordered_map<int, int> mp;
		for (auto i : arr) {
			mp[i]++;
		}

		// Create a max heap to store the frequency of each element
		priority_queue<int> pq;
		for (auto i : mp) {
			pq.push(i.second);
		}

		// Remove the elements from the heap until the removed elements are
		// greater than half of the array size
		int removed = 0, half = arr.size() / 2;
		int times = 0;
		while (!pq.empty() && removed < half) {
			removed += pq.top();
			pq.pop();
			times++;
		}

		return times;
	}
};
// @lc code=end
