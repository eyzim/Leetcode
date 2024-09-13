/*
 * @lc app=leetcode id=655 lang=cpp
 *
 * [655] Print Binary Tree
 *
 * @brief The implementation of the Solution class, which is used to print a
 * binary tree.
 *
 * The Solution class provides a method, printTree, that takes a TreeNode
 * pointer, root, as input and returns a vector of vectors of strings. The
 * method first calculates the height and width of the binary tree. It then
 * initializes a vector of vectors of strings, ans, with the height and width of
 * the binary tree. The method calls a helper function, dfs_print, to print the
 * binary tree. The dfs_print function takes the ans vector, the root node, the
 * row, the column, and the height of the binary tree as input. The dfs_print
 * function sets the value of the current node in the ans vector according to
 * the formula given in the description and recursively calls the dfs_print
 * function for the left and right subtrees. Finally, the method returns the ans
 * vector.
 *
 * Algorithm Complexity:
 * - The printTree method has a time complexity of O(n), where n is the number
 * of nodes in the binary tree.
 * - The space complexity of the method is O(n).
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
	// Helper function to print the binary tree
	// complexity: time O(n), space O(n)
	void dfs_print(vector<vector<string>>& ans,
				   TreeNode* root,
				   int r,
				   int c,
				   int height) {
		if (!root)
			return;

		// Set the value of the current node in the ans vector, according to the
		// formula given in the description
		ans[r][c] = to_string(root->val);
		dfs_print(ans, root->left, r + 1, c - pow(2, (height - r - 1)), height);
		dfs_print(ans, root->right, r + 1, c + pow(2, (height - r - 1)),
				  height);
	}

	// Get the maximum height of the binary tree
	// complexity: time O(n), space O(n)
	int dfs_height(TreeNode* node) {
		if (!node)
			return 0;

		return 1 + max(dfs_height(node->left), dfs_height(node->right));
	}

   public:
	vector<vector<string>> printTree(TreeNode* root) {
		if (!root)
			return {{}};

		// Get the height and width of the binary tree
		int height = dfs_height(root);
		int width = pow(2, height) - 1;
		vector<vector<string>> ans(height, vector<string>(width, ""));

		// Print the binary tree
		dfs_print(ans, root, 0, (width - 1) / 2, height - 1);

		return ans;
	}
};
// @lc code=end
