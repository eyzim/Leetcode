/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
 *
 * @brief The implementation of the Solution class, which is used to determine
 * if a binary tree is univalued.
 *
 * The Solution class provides a method, isUnivalTree, that takes a TreeNode
 * pointer, root, as input and returns a boolean value indicating whether the
 * binary tree is univalued. The method calls a helper function, dfs, to
 * traverse the binary tree and check if all the nodes have the same value as
 * the root node.
 *
 * Algorithm Complexity:
 * - The isUnivalTree method has a time complexity of O(n), where n is the
 * number of nodes in the binary tree.
 * - The space complexity of the method is O(1).
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
	bool dfs(TreeNode* node, int v) {
		if (!node)
			return true;

		// If the value of the current node is not equal to the value of the
		// root node, return false.
		if (node->val != v) {
			return false;
		}

		return dfs(node->left, v) && dfs(node->right, v);
	}

   public:
	bool isUnivalTree(TreeNode* root) {
		if (!root)
			return true;

		return dfs(root, root->val);
	}
};
// @lc code=end
