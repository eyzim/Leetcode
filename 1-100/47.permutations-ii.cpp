/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * @brief The implementation of the Solution class, which is used to find all
 * the permutations of a given list of numbers. But this time, the list of
 * numbers may contain duplicates.
 *
 * The implementation of the permute method using backtracking. The method first
 * initializes an empty vector of vectors, ans. It then calls the permute method
 * with the ans, nums, and 0 as arguments. The permute method is a helper method
 * that generates all the permutations of the given list of numbers. The method
 * first checks if the current index is equal to the size of the nums vector
 * minus 1. If it is, the method adds the current permutation to the ans vector.
 * Otherwise, the method iterates through the nums vector and swaps the current
 * element with all the elements after it. It then calls the permute method
 * recursively with the updated index. Finally, the method swaps back the
 * elements for the next iteration.
 *
 * Algorithm Complexity:
 * - The permute method has a time complexity of O(n!), where n is the number of
 * the elements in the nums vector.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
class Solution {
   private:
	void permute(vector<vector<int>>& ans, vector<int> nums, int start) {
		if (start == nums.size() - 1) {
			ans.push_back(nums);
		}

		for (int i = start; i < nums.size(); i++) {
			// if the current element is the same as the start element, skip it,
			// to avoid duplicates in the result array
			if (i != start && nums[i] == nums[start])
				continue;
			// try to swap the current element with all the elements after it
			swap(nums[start], nums[i]);
			// try to permute the rest of the elements
			permute(ans, nums, start + 1);
		}
	}

   public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		vector<vector<int>> ans;

		permute(ans, nums, 0);

		return ans;
	}
};
// @lc code=end
