/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 *
 * @brief The implementation of the Solution class, which is used to check if a
 * binary tree is a subtree of another binary tree.
 *
 * The solution uses a recursive approach to check if the binary tree is a
 * subtree of another binary tree. The isSameTree function is used to check if
 * two binary trees are the same. The isSubtree function is used to check if the
 * subtree is in the left or right subtree of the root.
 *
 * Algorithm Complexity:
 * - The isSameTree function has a time complexity of O(n), where n is the
 * number of nodes in the binary tree.
 * - The isSubtree function has a time complexity of O(n*m), where n is the
 * number of nodes in the binary tree and m is the number of nodes in the
 * subtree.
 * - The space complexity of the solution is O(n), where n is the number of
 * nodes in the binary tree.
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
	// The isSameTree function isSameTree is used to check if two binary trees
	// are the same.
	bool isSameTree(TreeNode* n1, TreeNode* n2) {
		if (!n1 && !n2)
			return true;
		if (!n1 || !n2)
			return false;
		if (n1->val != n2->val)
			return false;

		return isSameTree(n1->left, n2->left) &&
			   isSameTree(n1->right, n2->right);
	}

   public:
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (!root)
			return false;
		if (!subRoot)
			return true;

		if (isSameTree(root, subRoot)) {
			return true;
		}

		// Check if the subtree is in the left or right subtree of the root.
		return isSubtree(root->left, subRoot) ||
			   isSubtree(root->right, subRoot);
	}
};
// @lc code=end
