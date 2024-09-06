/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 *
 * @brief The implementation of the Solution class, which is used to find the k
 * pairs with the smallest sums.
 *
 * The Solution class provides a method, kSmallestPairs, that takes two vectors
 * of integers and an integer k as input and returns a vector of vectors of
 * integers representing the k pairs with the smallest sums. The method uses a
 * min heap to store the sum and the first number. It iterates over the two
 * vectors and calculates the sum of each pair. If the size of the min heap is
 * less than k, it pushes the sum and the first number into the min heap. If the
 * top element of the min heap is greater than the sum, it pops the top element
 * and pushes the sum and the first number into the min heap. Finally, it
 * creates a vector to store the k smallest pairs and pops the top k elements
 * from the min heap.
 *
 * Algorithm Complexity:
 * - The kSmallestPairs method has a time complexity of O(m*n*log(k)), where m
 * and n are the sizes of the two vectors.
 * - The space complexity of the method is O(k), where k is the size of the min
 * heap.
 */

// @lc code=start
class Solution {
   public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1,
									   vector<int>& nums2,
									   int k) {
		// Create a min heap to store the sum and the first number.
		// The heap sorts the top from the largest to the smallest
		priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
		for (auto i : nums1) {
			for (auto j : nums2) {
				int sum = i + j;
				if (pq.size() < k) {
					pq.push(make_pair(sum, i));
				} else if (pq.top().first > sum) {
					pq.pop();
					pq.push(make_pair(sum, i));
				} else {
					break;
				}
			}
		}

		// Create a vector to store the k smallest pairs.
		vector<vector<int>> ans;
		while (k--) {
			int sum = pq.top().first, n = pq.top().second;
			ans.push_back({n, sum - n});
			pq.pop();
		}

		return ans;
	}
};
// @lc code=end
