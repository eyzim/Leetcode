/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * @brief The implementation of the Solution class, which is used to calculate
 * the minimum depth of a binary tree.
 *
 * The minimum depth of a binary tree is the number of nodes along the shortest
 * path from the root node down to the nearest leaf node. The minimum depth of a
 * binary tree is the minimum depth of the left and right subtrees plus one.
 *
 * For example, if the binary tree is as follows:
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 * The minimum depth of the binary tree is 2, as the shortest path from the root
 * to a leaf node is [3, 20].
 *
 * The Solution class provides a method, minDepth, that takes a TreeNode pointer
 * root as input and returns the minimum depth of the binary tree. The method
 * uses a recursive approach to calculate the minimum depth of the left and
 * right subtrees. The final result is then returned based on the minimum depth
 * of the left and right subtrees.
 *
 * Algorithm Complexity:
 * - The minDepth method has a time complexity of O(n), where n is the number of
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
   public:
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;

		if (!root->left)
			return minDepth(root->right) + 1;
		if (!root->right)
			return minDepth(root->left) + 1;

		return 1 + min(minDepth(root->left), minDepth(root->right));
	}
};
// @lc code=end
