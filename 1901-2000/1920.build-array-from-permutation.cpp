/*
 * @lc app=leetcode id=1920 lang=cpp
 *
 * [1920] Build Array from Permutation
 *
 * @brief The implementation of the Solution class, which is used to build an
 * array from a permutation.
 *
 * The Solution class provides a method, buildArray, that takes a vector of
 * integers, nums, as input and returns a vector of integers.
 *
 * Algorithm Complexity:
 * - The buildArray method has a time complexity of O(n), where n is the number
 * of elements in the input vector.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
class Solution {
   public:
	vector<int> buildArray(vector<int>& nums) {
		vector<int> ans(nums.size());
		for (auto i = 0; i < ans.size(); i++) {
			ans[i] = nums[nums[i]];
		}

		return ans;
	}
};
// @lc code=end
