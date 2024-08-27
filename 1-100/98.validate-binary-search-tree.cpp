/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * @brief The implementation of the Solution class, which is used to determine
 * if a binary tree is a valid binary search tree.
 *
 * Given the root of a binary tree, determine if it is a valid binary search
 * tree (BST). A valid BST is defined as follows:
 * - The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * - The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * - Both the left and right subtrees must also be binary search trees.
 *
 * The Solution class provides a method, isValidBST, that takes a TreeNode
 * pointer root as input and returns true if the binary tree is a valid BST. The
 * method uses a recursive approach to check the validity of the left and right
 * subtrees. The final result is then returned based on the validity of the left
 * and right subtrees.
 *
 * Algorithm Complexity:
 * - The isValidBST method has a time complexity of O(n), where n is the number
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
	bool checkValidBST(TreeNode* node, long min, long max) {
		if (!node)
			return true;

		// Compare the current node's value with the min and max values
		if (min >= node->val || max <= node->val)
			return false;

		// Recursively check the left and right subtrees
		return checkValidBST(node->left, min, node->val) &&
			   checkValidBST(node->right, node->val, max);
	}

   public:
	bool isValidBST(TreeNode* root) {
		return checkValidBST(root, LLONG_MIN, LLONG_MAX);
	}
};
// @lc code=end
