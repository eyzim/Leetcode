/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 *
 * @brief The implementation of the Solution class, which is used to find the
 * average of levels in a binary tree.
 *
 * The Solution class provides a method, averageOfLevels, that takes a TreeNode
 * pointer as input and returns a vector of double values representing the
 * average of each level in the binary tree. The method uses a recursive
 * approach to traverse the tree and calculate the average of each level. It
 * initializes a vector of pairs, count, to store the sum and count of nodes at
 * each level. The method updates the count vector based on the values of the
 * nodes and their levels. Finally, it converts the count vector to the average
 * and returns the result.
 *
 * Algorithm Complexity:
 * - The averageOfLevels method has a time complexity of O(n), where n is the
 * number of nodes in the binary tree.
 * - The space complexity of the method is O(h), where h is the height of the
 * binary tree.
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   private:
	vector<pair<long, int>> count;

	void dfs(TreeNode* node, int depth) {
		if (!node)
			return;

		int v = node->val;
		// If the depth is greater than the size of the count vector, add a new
		// pair to the vector.
		if (count.size() <= depth) {
			count.push_back({v, 1});
		} else {
			// Otherwise, update the existing pair.
			count[depth].first += v;
			count[depth].second++;
		}

		// Traverse the left and right children nodes.
		dfs(node->left, depth + 1);
		dfs(node->right, depth + 1);
	}

   public:
	vector<double> averageOfLevels(TreeNode* root) {
		dfs(root, 0);

		// Convert the count to the average.
		vector<double> ans;
		for (int i = 0; i < count.size(); i++) {
			ans.push_back((double)count[i].first / count[i].second);
		}

		return ans;
	}
};
// @lc code=end
