/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * @brief The implementation of the Solution class, which is used to determine
 * if a binary tree is height-balanced.
 *
 * A height-balanced binary tree is defined as a binary tree in which the depth
 * of the two subtrees of every node never differs by more than one. The
 * Solution class provides a method, isBalanced, that takes a TreeNode pointer
 * root as input and returns true if the binary tree is height-balanced. The
 * method uses a recursive approach to calculate the height of the left and
 * right subtrees of each node. The final result is then returned based on the
 * height of the left and right subtrees.
 *
 * Algorithm Complexity:
 * - The isBalanced method has a time complexity of O(n), where n is the number
 * of nodes in the binary tree.
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
	int checkBalance(TreeNode* node) {
		// if the node is a leaf node, return 0
		if (!node)
			return 0;

		// If left subtree is unbalanced, propagate -1 up
		int left = checkBalance(node->left);
		if (left == -1)
			return -1;

		// If right subtree is unbalanced, propagate -1 up
		int right = checkBalance(node->right);
		if (right == -1)
			return -1;

		// If the current node is unbalanced, return -1
		if (abs(left - right) > 1)
			return -1;

		// Otherwise, return the height of the subtree rooted at the current
		// node
		return 1 + max(left, right);
	}

   public:
	bool isBalanced(TreeNode* root) {
		if (!root)
			return true;

		return checkBalance(root) != -1;
	}
};
// @lc code=end
