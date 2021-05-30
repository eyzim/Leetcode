/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition
 *
 * @brief The implementation of the Solution class, which is used to find the
 * sum of the minimum of the pair of numbers.
 *  *
 * The array is not sorted, so we need to sort the array first. Then, we can
 * find the sum of the minimum of the pair of numbers which is the sum of the
 * even-indexed numbers (the first number of each pair).
 *
 * Algorithm Complexity:
 * - The arrayPairSum method has a time complexity of O(nlogn), where n is the
 * length of the input array.
 * - The space complexity of the arrayPairSum method is O(1).
 */

// @lc code=start
class Solution {
   public:
	int arrayPairSum(vector<int>& nums) {
		ranges::sort(nums);
		int ans = 0;

		for (auto i = 0; i < nums.size(); i += 2) {
			ans += nums[i];
		}

		return ans;
	}
};
// @lc code=end
