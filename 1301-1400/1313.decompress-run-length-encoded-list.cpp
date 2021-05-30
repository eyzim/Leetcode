/*
 * @lc app=leetcode id=1313 lang=cpp
 *
 * [1313] Decompress Run-Length Encoded List
 *
 * @brief The implementation of the Solution class, which is used to decompress
 * a run-length encoded list.
 *
 * The Solution class provides a method, decompressRLElist, that takes a list of
 * integers as input and returns a list of integers that are the decompressed
 * version of the input list.
 *
 * Algorithm Complexity:
 * - The decompressRLElist method has a time complexity of O(n), where n is the
 * length of the input list.
 * - The space complexity of the decompressRLElist method is O(n).
 */

// @lc code=start
class Solution {
   public:
	vector<int> decompressRLElist(vector<int>& nums) {
		vector<int> ans = {};

		for (auto i = 0; i < nums.size(); i += 2) {
			int freq = nums[i], val = nums[i + 1];
			ans.insert(ans.end(), freq, val);
		}

		return ans;
	}
};
// @lc code=end
