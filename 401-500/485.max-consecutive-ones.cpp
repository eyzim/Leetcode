/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 *
 * @brief Find the maximum number of consecutive 1s in an array of 0s and 1s.
 *
 * The Solution class provides a method, findMaxConsecutiveOnes, that takes an
 * array of 0s and 1s as input and returns the maximum number of consecutive 1s
 * in the array.
 *
 * Algorithm Complexity:
 * - The findMaxConsecutiveOnes method has a time complexity of O(n), where n is
 * the length of the input array.
 * - The space complexity of the findMaxConsecutiveOnes method is O(1).
 */

// @lc code=start
class Solution {
   public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int ans = 0, temp = 0;

		// iterate through the array and count the number of consecutive 1s
		for (const auto i : nums) {
			if (i) {
				temp++;
			} else {
				ans = max(ans, temp);
				temp = 0;
			}
		}

		// check if the last element is 1
		ans = max(ans, temp);

		return ans;
	}
};
// @lc code=end
