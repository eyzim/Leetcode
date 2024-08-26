/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 *
 * @brief The implementation of the Solution class, which is used to calculate
 * the maximum depth of a binary tree.
 *
 * The depth of the tree is the number of nodes along the longest path from the
 * root node down to the farthest leaf node. The maximum depth of a binary tree
 * is the maximum depth of the left and right subtrees plus one.
 *
 * For example, if the binary tree is as follows:
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * The maximum depth of the binary tree is 3, as the longest path from the root
 * to a leaf node is [3, 20, 7].
 *
 * The Solution class provides a method, maxDepth, that takes a TreeNode pointer
 * root as input and returns the maximum depth of the binary tree. The method
 * uses a recursive approach to calculate the maximum depth of the left and
 * right subtrees. The final result is then returned based on the maximum depth
 * of the left and right subtrees.
 *
 * Algorithm Complexity:
 * - The maxDepth method has a time complexity of O(n), where n is the number of
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
	int maxDepth(TreeNode* root) {
		int ans = 0;

		if (!root)
			return 0;
		else
			ans++;

		return ans + max(maxDepth(root->left), maxDepth(root->right));
	}
};
// @lc code=end
