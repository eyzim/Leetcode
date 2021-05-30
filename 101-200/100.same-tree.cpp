/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 *
 * @brief The implementation of the Solution class, which is used to determine
 * if two binary trees are the same.
 *
 * The Solution class provides a method, isSameTree, that takes two TreeNode
 * pointers as input and returns a boolean value indicating whether the two
 * binary trees are the same. The method uses a recursive approach to compare
 * the nodes of the two trees. If the nodes are equal, the method recursively
 * compares the left and right subtrees of the two trees. If any of the nodes
 * are not equal, the method returns false. If both trees are empty, the method
 * returns true.
 *
 * Algorithm Complexity:
 * - The isSameTree method has a time complexity of O(n), where n is the number
 * of nodes in the binary tree. The method visits each node once.
 * - The space complexity of the method is O(n), where n is the number of nodes
 * in the binary tree. The method uses the call stack for recursion, which can
 * go up to the height of the tree.
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q)
			return true;
		if (!p || !q)
			return false;
		if (p->val != q->val)
			return false;

		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};
// @lc code=end
