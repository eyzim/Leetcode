/*
 * @lc app=leetcode id=1389 lang=cpp
 *
 * [1389] Create Target Array in the Given Order
 *
 * @brief The implementation of the Solution class, which is used to create a
 * target array in the given order.
 *
 * The Solution class provides a method, createTargetArray, that takes two
 * vectors of integers as input and returns a vector of integers. The method
 * inserts the elements of the first vector into the target array at the
 * positions specified by the second vector.
 *
 * Algorithm Complexity:
 * - The time complexity of the createTargetArray method is O(n^2), where n is
 * the length of the input vectors.
 * - The space complexity of the createTargetArray method is O(n).
 */

// @lc code=start
class Solution {
   public:
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		vector<int> ans;

		for (auto i = 0; i < nums.size(); i++) {
			ans.insert(ans.begin() + index[i], nums[i]);
		}

		return ans;
	}
};
// @lc code=end
