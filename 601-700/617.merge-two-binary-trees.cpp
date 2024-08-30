/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
 *
 * @brief The implementation of the Solution class, which is used to merge two
 * binary trees.
 *
 * The Solution class provides a method, mergeTrees, that takes two TreeNode
 * pointers as input and returns a TreeNode pointer representing the merged
 * binary tree. The method uses a recursive approach to merge the two trees. It
 * adds the values of the two nodes and recursively merges the left and right
 * subtrees. The method returns the merged tree.
 *
 * Algorithm Complexity:
 * - The mergeTrees method has a time complexity of O(n), where n is the number
 * of nodes in the binary tree.
 * - The space complexity of the method is O(1), as it does not use any extra
 * space.
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
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		if (!root1 && !root2)
			return NULL;
		if (!root1)
			return root2;
		if (!root2)
			return root1;

		// Merge the values of the two nodes.
		root1->val += root2->val;

		// Recursively merge the left and right subtrees.
		root1->left = mergeTrees(root1->left, root2->left);
		root1->right = mergeTrees(root1->right, root2->right);

		return root1;
	}
};
// @lc code=end
