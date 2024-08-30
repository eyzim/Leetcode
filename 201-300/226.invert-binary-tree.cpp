/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 *
 * @brief The implementation of the Solution class, which is used to invert a
 * binary tree.
 *
 * The Solution class provides a method, invertTree, that takes a TreeNode
 * pointer as input and returns a TreeNode pointer. The method inverts the
 * binary tree by swapping the left and right children of each node. The method
 * uses a recursive approach to invert the left and right subtrees of the
 * current node. If the current node is a leaf node, the method returns without
 * inverting the children. The method then swaps the left and right children of
 * the current node. The method returns the root of the inverted binary tree.
 *
 * Algorithm Complexity:
 * - The invertTree method has a time complexity of O(n), where n is the number
 * of nodes in the binary tree. The method visits each node once.
 * - The space complexity of the method is O(1) since the method does not use
 * any extra space.
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
	void invert(TreeNode* node) {
		if (!node)
			return;

		// Invert the left and right subtrees of the current node.
		invert(node->left);
		invert(node->right);

		// Swap the left and right children of the current node.
		if (!node->left && !node->right)
			return;
		TreeNode* t = node->left;
		node->left = node->right;
		node->right = t;
	}

   public:
	TreeNode* invertTree(TreeNode* root) {
		invert(root);

		return root;
	}
}
// @lc code=end
