/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * @brief The implementation of the Solution class, which is used to generate
 * the Pascal's triangle.
 *
 * The implementation of the generate method generates the Pascal's triangle up
 * to the given number of rows. The method initializes the triangle with the
 * first row containing a single element 1. It then builds the triangle row by
 * row by adding the previous row's elements. The method returns the generated
 * triangle.
 *
 * Algorithm Complexity:
 * - The generate method has a time complexity of O(n^2), where n is the number
 * of rows in the triangle.
 * - The space complexity of the method is O(n^2), where n is the number of rows
 * in the triangle.
 */

// @lc code=start
class Solution {
   private:
	void build(vector<vector<int>>& ans) {
		int size = ans.back().size();
		vector<int> level(size + 1, 1);

		// Build the level by adding the previous level's elements
		for (int i = 1; i < size; i++) {
			level[i] = ans[size - 1][i - 1] + ans[size - 1][i];
		}

		ans.push_back(level);
	}

   public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans = {{1}};

		// Build the triangle row by row
		for (int i = 1; i < numRows; i++) {
			build(ans);
		}

		return ans;
	}
};
// @lc code=end
