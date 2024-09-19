/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * @brief The implementation of the Solution class, which is used to find the
 * largest number that can be formed by concatenating the elements of a given
 * array.
 *
 * The Solution class provides a method, largestNumber, that takes a vector of
 * integers, nums, as input and returns the largest number that can be formed by
 * concatenating the elements of the array. The method first checks if the size
 * of the input array is 1 and returns the element as a string if it is. It then
 * sorts the array using a custom comparator function, comp, which compares the
 * concatenation of two numbers in both orders. Finally, it concatenates the
 * sorted numbers and returns the result as a string.
 *
 * Algorithm Complexity:
 * - The largestNumber method has a time complexity of O(nlogn), where n is the
 * number of elements in the input array.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
bool comp(int a, int b) {
	return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

class Solution {
   public:
	string largestNumber(vector<int>& nums) {
		if (nums.size() == 1)
			return to_string(nums[0]);
		// Sort the array using the custom comparator function
		sort(nums.begin(), nums.end(), comp);

		string ans = "";
		for (auto i = 0; i < nums.size(); i++) {
			// Skip leading zeros
			if (nums[i] == 0 && ans.size() == 0) {
				continue;
			}
			ans += to_string(nums[i]);
		}

		return ans.size() ? ans : "0";
	}
};
// @lc code=end
