/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * @brief The implementation of the Solution class, which is used to determine
 * if a binary tree is symmetric.
 *
 * The symmetric means the left subtree is a mirror reflection of the right
 * subtree. Two trees are a mirror reflection of each other if the following
 * conditions are true:
 * - Their two roots have the same value.
 * - The right subtree of each tree is a mirror reflection of the left subtree
 * of the other tree.
 * The Solution class provides a method, isSymmetric, that
 * takes a TreeNode pointer as input and returns a boolean value indicating
 * whether the binary tree is symmetric. The method uses a recursive approach to
 * compare the left and right subtrees of the root node to determine if the tree
 * is symmetric.
 *
 * Algorithm Complexity:
 * - The isSymmetric method has a time complexity of O(n), where n is the number
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
	bool isSym(TreeNode* node1, TreeNode* node2) {
		if (!node1 && !node2)
			return true;

		if (!node1 || !node2)
			return false;

		return (node1->val == node2->val) && isSym(node1->left, node2->right) &&
			   isSym(node1->right, node2->left);
	}

   public:
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;

		return isSym(root->left, root->right);
	}
};
// @lc code=end
