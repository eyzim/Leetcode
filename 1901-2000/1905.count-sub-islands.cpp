/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 *
 * @brief The implementation of the Solution class, which is used to count the
 * number of sub-islands.
 *
 * The Solution class provides a method, countSubIslands, that takes two 2D
 * vectors of integers as input and returns an integer value representing the
 * number of sub-islands. The method uses a depth-first search (DFS) approach to
 * traverse the islands in the second grid and check if they are sub-islands of
 * the first grid. If the current cell is out of bounds or is water, the method
 * returns. If the island in the second grid is not a sub-island, the method
 * sets a flag to false. The method marks the current cell as visited and
 * recursively calls itself on the adjacent cells. The method returns the count
 * of sub-islands.
 *
 * Algorithm Complexity:
 * - The countSubIslands method has a time complexity of O(m*n), where m is the
 * number of rows and n is the number of columns in the grid.
 * - The space complexity of the method is O(1), which does not include the
 * space used by the output.
 */

// @lc code=start
class Solution {
   private:
	bool isSubIsland;

	void dfs(vector<vector<int>>& grid1,
			 vector<vector<int>>& grid2,
			 int i,
			 int j) {
		// If the current cell is out of bounds or is water, return.
		if (i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() ||
			grid2[i][j] == 0)
			return;

		// If the island in grid2 is not a sub-island, return.
		if (grid1[i][j] == 0) {
			isSubIsland = false;
		}
		// Mark the current cell as visited.
		grid2[i][j] = 0;

		// Recursively call the method on the adjacent cells.
		dfs(grid1, grid2, i - 1, j);
		dfs(grid1, grid2, i + 1, j);
		dfs(grid1, grid2, i, j - 1);
		dfs(grid1, grid2, i, j + 1);
	}

   public:
	int countSubIslands(vector<vector<int>>& grid1,
						vector<vector<int>>& grid2) {
		int count = 0;

		for (auto i = 0; i < grid2.size(); i++) {
			for (auto j = 0; j < grid2[0].size(); j++) {
				if (grid2[i][j] == 1) {
					// Reset the flag for each island.
					isSubIsland = true;
					// Check if the island in grid2 is a sub-island and mark all
					// the lands of one island in grid2.
					dfs(grid1, grid2, i, j);

					// If the island in grid2 is a sub-island, increment the
					// count.
					if (isSubIsland) {
						count++;
					}
				}
			}
		}

		return count;
	}
};
// @lc code=end
