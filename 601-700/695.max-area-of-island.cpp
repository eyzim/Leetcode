/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * @brief The implementation of the Solution class, which is used to find the
 * maximum area of an island.
 *
 * The Solution class provides a method, maxAreaOfIsland, that takes a 2D vector
 * of integers as input and returns an integer value representing the maximum
 * area of an island. The grid represents a map of land and water, where 0
 * represents water and 1 represents land. The island is a single connected land
 * mass, and the area is the total number of cells in the island. The method
 * uses a depth-first search (DFS) approach to traverse the island and calculate
 * the area. If the current cell is out of bounds or is water, the method
 * returns 0. If the current cell is land, the method marks the cell as visited
 * and recursively calls itself on the adjacent cells. The method returns the
 * sum of the area of the adjacent cells.
 *
 * Algorithm Complexity:
 * - The maxAreaOfIsland method has a time complexity of O(m*n), where m is the
 * number of rows and n is the number of columns in the grid.
 * - The space complexity of the method is O(1), which does not include the
 * space used by the output.
 */

// @lc code=start
class Solution {
   private:
	int dfs(vector<vector<int>>& grid, int i, int j) {
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
			grid[i][j] == 0)
			return 0;

		grid[i][j] = 0;

		return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) +
			   dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
	}

   public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int maxi = 0;

		for (auto i = 0; i < grid.size(); i++) {
			for (auto j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					maxi = max(maxi, dfs(grid, i, j));
				}
			}
		}

		return maxi;
	}
};
// @lc code=end
