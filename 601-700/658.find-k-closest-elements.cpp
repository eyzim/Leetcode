/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 *
 * @brief The implementation of the Solution class, which is used to find the k
 * closest elements to a given integer x in an array.
 *
 * The Solution class provides a method, findClosestElements, that takes a
 * vector of integers, arr, an integer, k, and an integer, x, as input and
 * returns a vector of the k closest elements to x in arr. The method
 * initializes a priority queue, pq, to store the k closest elements to x. It
 * then iterates through the elements in arr, calculates the absolute difference
 * between each element and x, and pushes the pair of the absolute difference
 * and the element into pq. If the size of pq exceeds k, the method pops the top
 * element. Finally, the method constructs a vector, ans, from the elements in
 * pq, sorts the vector, and returns it.
 *
 * Algorithm Complexity:
 * - The findClosestElements method has a time complexity of O(n log k), where n
 * is the number of elements in arr.
 * - The space complexity of the method is O(k).
 */

// @lc code=start
class Solution {
   public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		// Create a priority queue to store the k closest elements to x in arr
		priority_queue<pair<int, int>> pq;
		for (auto i : arr) {
			pq.push({abs(i - x), i});
			// If the size of pq exceeds k, pop the top element which has the
			// largest absolute difference
			if (pq.size() > k) {
				pq.pop();
			}
		}

		// Construct a vector from the elements in pq
		vector<int> ans;
		while (!pq.empty()) {
			ans.push_back(pq.top().second);
			pq.pop();
		}

		// According to the problem statement, the elements in the vector should
		// be sorted
		sort(ans.begin(), ans.end());

		return ans;
	}
};
// @lc code=end
