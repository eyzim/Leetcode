/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 *
 * @brief The implementation of the Solution class, which is used to find the
 difference of two arrays.
 *
 * The Solution class provides a method, findDifference, that takes two vectors
 of integers as input and returns a vector of two vectors of integers that
 contain the elements that are present in one array but not in the other.
 *
 * Algorithm Complexity:
 * - The time complexity of the findDifference method is O(n + m), where n and m
 are the lengths of the input arrays.
 * - The space complexity of the findDifference method is O(n + m).
 */

// @lc code=start
class Solution {
   public:
	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
		// Remove the duplicates from the input arrays
		unordered_set<int> mp1(nums1.begin(), nums1.end());
		unordered_set<int> mp2(nums2.begin(), nums2.end());

		vector<int> n1, n2;

		// Find the elements that are present in the first array but not in the
		// second array
		for (auto i : mp1) {
			if (mp2.count(i) == 0) {
				n1.push_back(i);
			}
		}

		// Find the elements that are present in the second array but not in the
		// first array
		for (auto i : mp2) {
			if (mp1.count(i) == 0) {
				n2.push_back(i);
			}
		}

		return {n1, n2};
	}
};
// @lc code=end
