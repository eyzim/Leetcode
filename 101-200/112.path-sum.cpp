/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * @brief The implementation of the Solution class, which is used to determine
 * if there is a root-to-leaf path in a binary tree that has a specific sum.
 *
 * Given the root of a binary tree and an integer targetSum, return true if
 * there is a root-to-leaf path in the binary tree such that adding up all the
 * values along the path equals targetSum. A leaf is a node with no children.
 *
 * For example, if the binary tree is as follows:
 *    5
 *   / \
 *  4   8
 *     / \
 *   11  13
 *   / \
 *  7   2
 * The targetSum is 22, and the root-to-leaf path 5 -> 8 -> 4 -> 5 has a sum
 * of 22.
 *
 * The Solution class provides a method, hasPathSum, that takes a TreeNode
 * pointer root and an integer targetSum as input and returns true if there is a
 * root-to-leaf path in the binary tree that has a sum equal to targetSum. The
 * method uses a recursive approach to calculate the sum of the left and right
 * subtrees. The final result is then returned based on the sum of the left and
 * right subtrees.
 *
 * Algorithm Complexity:
 * - The hasPathSum method has a time complexity of O(n), where n is the number
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
   public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (!root)
			return false;

		targetSum -= root->val;
		if (!targetSum && !root->left && !root->right)
			return true;

		return hasPathSum(root->left, targetSum) ||
			   hasPathSum(root->right, targetSum);
	}
};
// @lc code=end
