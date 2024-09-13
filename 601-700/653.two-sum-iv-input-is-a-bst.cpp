/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * @brief The implementation of the Solution class, which is used to find if
 * there are two elements in a binary search tree that add up to a specific
 * value.
 *
 * The Solution class provides a method, findTarget, that takes a TreeNode
 * pointer, root, and an integer, k, as input and returns true if there are two
 * elements in the binary search tree that add up to k and false otherwise. The
 * method first initializes a vector of integers, n, and calls a helper
 * function, inorder, to get the inorder traversal of the binary search tree. It
 * then initializes an unordered set of integers, mp, and traverses the inorder
 * traversal to check if the sum of two numbers is k. If it finds a pair of
 * numbers that add up to k, it returns true; otherwise, it returns false.
 *
 * Algorithm Complexity:
 * - The findTarget method has a time complexity of O(n), where n is the number
 * of nodes in the binary search tree.
 * - The space complexity of the method is O(n).
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
	void inorder(vector<int>& n, TreeNode* node) {
		if (!node)
			return;

		inorder(n, node->left);
		n.push_back(node->val);
		inorder(n, node->right);
	}

   public:
	bool findTarget(TreeNode* root, int k) {
		if (!root)
			return false;

		// Get the inorder traversal of the BST
		vector<int> n;
		inorder(n, root);

		// Traverse the inorder traversal and check if the sum of two numbers is
		// k
		unordered_set<int> mp;
		for (auto i : n) {
			if (mp.count(k - i)) {
				return true;
			}
			mp.insert(i);
		}

		return false;
	}
};
// @lc code=end
