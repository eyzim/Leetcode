/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * @brief The implementation of the Solution class, which is used to find all
 * the permutations of a given list of numbers.
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
 * elements in the nums vector.
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
			// try to swap the current element with all the elements after it
			swap(nums[start], nums[i]);
			// try to permute the rest of the elements
			permute(ans, nums, start + 1);
		}
	}

   public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;

		permute(ans, nums, 0);

		return ans;
	}
};
// @lc code=end
