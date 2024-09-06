/*
 * @lc app=leetcode id=2500 lang=cpp
 *
 * [2500] Delete Greatest Value in Each Row
 *
 * @brief The implementation of the Solution class, which is used to find the
 * sum of the greatest values in each column of the grid.
 *
 * There are two solutions to this problem. The first solution uses a priority
 * queue to store the elements of each column in the grid. It then iterates
 * through the columns and pushes the elements into the priority queue. After
 * that, it calculates the sum of the greatest values in each column by popping
 * the elements from the priority queue.
 * The second solution uses a linear
 * search algorithm to find the greatest value in each column of the grid. It
 * iterates through the columns and calculates the sum of the greatest values in
 * each column by finding the maximum value in each column.
 *
 * Algorithm Complexity:
 * - The two solutions both have a time complexity of O(m * n * log n), where m
 * is the number of rows and n is the number of columns in the grid.
 * - The space complexity of the first solution is O(n), where n is the number
 * of columns in the grid.
 * - The space complexity of the second solution is O(1).
 */

// @lc code=start
class Solution1 {
   public:
	int deleteGreatestValue(vector<vector<int>>& grid) {
		// Sort each row in the grid
		for (auto row : grid) {
			sort(row.begin(), row.end());
		}

		// Calculate the sum of the greatest values in each column
		int ans = 0;
		for (auto i = 0; i < grid[0].size(); i++) {
			priority_queue<int, vector<int>> pq;
			for (auto j = 0; j < grid.size(); j++) {
				pq.push(grid[j][i]);
			}
			ans += pq.top();
		}

		return ans;
	}
};

class Solution2 {
   public:
	int deleteGreatestValue(vector<vector<int>>& grid) {
		// Sort each row in the grid
		for (auto row : grid) {
			sort(row.begin(), row.end());
		}

		// Calculate the sum of the greatest values in each column
		int ans = 0;
		for (auto i = 0; i < grid[0].size(); i++) {
			int maxi = INT_MIN;
			for (auto j = 0; j < grid.size(); j++) {
				maxi = max(maxi, grid[j][i]);
			}
			ans += maxi;
		}

		return ans;
	}
};
// @lc code=end
