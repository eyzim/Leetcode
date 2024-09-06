/*
 * @lc app=leetcode id=3264 lang=cpp
 *
 * [3264] Final Array State After K Multiplication Operations I
 *
 * @brief The implementation of the Solution class, which is used to find the
 final state of the array after performing k multiplication operations.
 *
 * The solution uses a priority queue to store the elements of the array along
 with their indices. It then iterates through the array and pushes the elements
 into the priority queue. After that, it performs k multiplication operations by
 multiplying the top element of the priority queue with the multiplier and
 pushing it back into the priority queue. Finally, it constructs the final state
 of the array by popping the elements from the priority queue and storing them
 in the result array.
 *
 * Algorithm Complexity:
 * - The solution has a time complexity of O(n log n), where n is the size of
 the array.
 * - The solution has a space complexity of O(n).
 */

// @lc code=start
class Solution {
   public:
	vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
		// Create a priority queue to store the elements from smallest to
		// largest and store the indices of the elements
		priority_queue<pair<int, int>, vector<pair<int, int>>,
					   greater<pair<int, int>>>
			pq;
		for (auto i = 0; i < nums.size(); i++) {
			pq.push(make_pair(nums[i], i));
		}

		// Perform k multiplication operations by multiplying the top element of
		// the priority queue with the multiplier and pushing it back into the
		// priority queue
		while (k--) {
			pq.push(make_pair(pq.top().first * multiplier, pq.top().second));
			pq.pop();
		}

		// Construct the final state of the array by popping the elements from
		// the priority queue
		vector<int> ans(nums.size());
		while (!pq.empty()) {
			ans[pq.top().second] = pq.top().first;
			pq.pop();
		}

		return ans;
	}
};
// @lc code=end
