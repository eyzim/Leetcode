/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * @brief : Given an integer rowIndex, return the rowIndexth row of the Pascal's
 * triangle in O(k) space.
 *
 * The solution is similar to 118.pascals-triangle.cpp, but we only need to
 * return the rowIndexth row. First, we initialize the first row as {1}, then we
 * build the next row based on the previous row. Second, we build the next row
 * based on the previous row. While building the next row, we need to update the
 * value of the current element based on the previous element and the current
 * element. Finally, we return the rowIndexth row.
 *
 * Algorithm Complexity:
 * - Time: O(k^2)
 * - Space: O(k)
 */

// @lc code=start
class Solution {
   private:
	void build(vector<int>& ans) {
		// We need to update the value of the current element based on the
		// previous element and the current element.
		int pre = 1, now;

		for (int i = 1; i < ans.size(); i++) {
			now = ans[i];
			ans[i] = pre + now;
			pre = now;
		}

		// Add the last element to the end of the row.
		ans.push_back(1);
	}

   public:
	vector<int> getRow(int rowIndex) {
		vector<int> ans = {1};

		// Build the next row based on the previous row.
		for (auto i = 1; i <= rowIndex; i++) {
			build(ans);
		}

		return ans;
	}
};
// @lc code=end
