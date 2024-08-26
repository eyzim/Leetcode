/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * @brief The implementation of the Solution class, which is used to calculate
 * the sum of all left leaves in a binary tree.
 *
 * First we have to find the sum of all left leaves in a given binary tree. The
 * left leaf means that the node has no children and is located on the left side
 * of the tree. The Solution class provides a method, sumOfLeftLeaves, that
 * takes a TreeNode pointer root as input and returns the sum of all left leaves
 * in the binary tree. The method uses a recursive approach to calculate the sum
 * of the left and right subtrees. The final result is then returned based on
 * the sum of the left and right subtrees.
 *
 * Algorithm Complexity:
 * - The sumOfLeftLeaves method has a time complexity of O(n), where n is the
 * number of nodes in the binary tree.
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
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root)
			return 0;

		int ans = 0;
		if (root->left && !root->left->left && !root->left->right) {
			ans += root->left->val;
		}

		return ans + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
};
// @lc code=end
