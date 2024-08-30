/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
 *
 * @brief The implementation of the Solution class, which is used to find the
 * tilt of a binary tree.
 *
 * The Solution class provides a method, findTilt, that takes a TreeNode pointer
 * as input and returns an integer value representing the tilt of the binary
 * tree. The method uses a recursive approach to traverse the tree and calculate
 * the tilt. It initializes a variable, sum, to store the sum of the nodes and
 * updates it based on the difference between the left and right subtrees. The
 * method returns the sum of the tilt of the binary tree.
 *
 *
 * Algorithm Complexity:
 * - The findTilt method has a time complexity of O(n), where n is the number of
 * nodes in the binary tree.
 * - The space complexity of the method is O(n), where n is the number of nodes
 * in the binary tree.
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
	int sum = 0;
	int dfs(TreeNode* node) {
		if (!node)
			return 0;

		int l = dfs(node->left);
		int r = dfs(node->right);
		sum += abs(l - r);

		return l + r + node->val;
	}

   public:
	int findTilt(TreeNode* root) {
		if (!root)
			return 0;
		dfs(root);

		return sum;
	}
};
// @lc code=end
