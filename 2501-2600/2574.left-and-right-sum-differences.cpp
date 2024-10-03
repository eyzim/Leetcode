/*
 * @lc app=leetcode id=2574 lang=cpp
 *
 * [2574] Left and Right Sum Differences
 *
 * @brief Find the difference between the left and right sum of the array.
 *
 * 1. Solution 1
 * The idea is to find the difference between the left and right sum of the
 * array. First, we need to calculate the prefix sum of the array. Then, we can
 * find the sum of the array. Next, we iterate through the array and calculate
 * the difference between the left and right sum of the array. Finally, we
 * return the array with the difference between the left and right sum of the
 * array.
 * 2. Solution 2
 * The idea is to find the difference between the left and right sum of the
 * array. We can use two pointers, left and right, to represent the left and
 * right sum of the array. First, we calculate the sum of the array. Then, we
 * iterate through the array and calculate the difference between the left and
 * right sum of the array. Finally, we return the array with the difference
 * between the left and right sum of the array.
 *
 * Algorithm Complexity:
 * 1. Solution 1
 * - Time complexity: O(n)
 * - Space complexity: O(n)
 * 2. Solution 2
 * - Time complexity: O(n)
 * - Space complexity: O(1)
 */

// @lc code=start
class Solution1 {
   public:
	vector<int> leftRightDifference(vector<int>& nums) {
		// Calculate the prefix sum of the array, mind that the first element is
		// 0
		vector<int> prefix(nums.size() + 1, 0);

		for (int i = 0; i < nums.size(); i++) {
			prefix[i + 1] = prefix[i] + nums[i];
		}

		int sum = prefix.back();

		for (int i = 0; i < nums.size(); i++) {
			nums[i] = abs((sum - prefix[i + 1]) - prefix[i]);
		}

		return nums;
	}
};

class Solution2 {
   public:
	vector<int> leftRightDifference(vector<int>& nums) {
		// Calculate the sum of the array
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int left = 0;

		for (int i = 0; i < nums.size(); i++) {
			int right = sum - left - nums[i];
			nums[i] = abs(left - right);
			left += nums[i];
		}

		return nums;
	}
}
// @lc code=end
