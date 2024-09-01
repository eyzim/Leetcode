/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * @brief The implementation of the Solution class, which is used to recover a
 * binary search tree.
 *
 * The Solution class provides a method, recoverTree, that takes a TreeNode
 * pointer, root, as input and recovers the binary search tree. First, it
 * initializes two TreeNode pointers, n1 and n2, to NULL and a TreeNode pointer,
 * pre, to a new TreeNode with a value of INT_MIN. It then calls a helper
 * function, inorder, to traverse the binary search tree in inorder. The inorder
 * function takes a TreeNode pointer, node, as input and recursively traverses
 * the left subtree, checks if the current node is out of order, and updates n1
 * and n2 accordingly, and then traverses the right subtree. Finally, the method
 * swaps the values of n1 and n2 if they are not NULL.
 *
 * Algorithm Complexity:
 * - The recoverTree method has a time complexity of O(n), where n is the number
 * of nodes in the binary search tree.
 * - The space complexity of the method is O(1).
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
	TreeNode* n1 = NULL;
	TreeNode* n2 = NULL;
	TreeNode* pre = new TreeNode(INT_MIN);

	void inorder(TreeNode* node) {
		if (!node)
			return;

		inorder(node->left);

		if (pre && pre->val > node->val) {
			if (!n1) {
				n1 = pre;
			}
			n2 = node;
		}
		pre = node;

		inorder(node->right);
	}

   public:
	void recoverTree(TreeNode* root) {
		inorder(root);

		if (n1 && n2) {
			swap(n1->val, n2->val);
		}
	}
};
// @lc code=end
