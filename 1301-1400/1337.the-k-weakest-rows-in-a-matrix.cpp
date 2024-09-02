/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 *
 * @brief The implementation of the Solution class, which is used to find the k
 * weakest rows in a matrix.
 *
 * The Solution class provides a method, kWeakestRows, that takes a 2D vector of
 * integers and an integer k as input and returns a vector of integers
 * representing the k weakest rows in the matrix. The method uses a min heap to
 * store the number of soldiers and the row index. It iterates over the matrix
 * and counts the number of soldiers in each row. It pushes the number of
 * soldiers and the row index into the min heap. It creates a vector to store
 * the k weakest rows and pops the top k elements from the min heap.
 *
 * Algorithm Complexity:
 * - The kWeakestRows method has a time complexity of O(m*n*log(m)), where m is
 * the number of rows and n is the number of columns in the matrix.
 * - The space complexity of the method is O(m), where m is the number of rows
 * in the matrix.
 */

// @lc code=start
class Solution {
   public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		// Create a min heap to store the number of soldiers and the row index.
		priority_queue<pair<int, int>, vector<pair<int, int>>,
					   greater<pair<int, int>>>
			pq;

		// Iterate over the matrix and count the number of soldiers in each row.
		for (auto i = 0; i < mat.size(); i++) {
			int sol = 0;
			for (auto j = 0; j < mat[i].size(); j++) {
				if (mat[i][j])
					sol++;
			}
			// Push the number of soldiers and the row index into the min heap.
			pq.push(make_pair(sol, i));
		}

		// Create a vector to store the k weakest rows.
		vector<int> ans(k);
		for (auto i = 0; i < k; i++) {
			ans[i] = pq.top().second;
			pq.pop();
		}

		return ans;
	}
};
// @lc code=end
