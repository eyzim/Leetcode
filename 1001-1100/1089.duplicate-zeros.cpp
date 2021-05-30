/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 *
 * @brief The implementation of the Solution class, which is used to duplicate
 * each occurrence of zero in an array. And remove the extra elements, which are
 * beyond the original length of the array.
 *
 * The Solution class provides a method, duplicateZeros, that takes an array of
 * integers as input and duplicates each occurrence of zero, shifting the
 * remaining elements to the right. The extra elements beyond the original
 * length of the array are removed.
 *
 * Algorithm Complexity:
 * - The duplicateZeros method has a time complexity of O(n^2), where n is the
 * length of the input array.
 * - The space complexity of the duplicateZeros method is O(1).
 *
 */

// @lc code=start
class Solution {
   public:
	void duplicateZeros(vector<int>& arr) {
		for (auto i = 0; i < arr.size(); i++) {
			if (arr[i] == 0) {
				// insert the extra 0 at the current position
				arr.insert(arr.begin() + i, 0);
				// remove the last element to maintain the original length
				arr.pop_back();
				i++;
			}
		}
	}
};
// @lc code=end
