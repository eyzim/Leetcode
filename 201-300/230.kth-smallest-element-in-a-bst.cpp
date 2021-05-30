/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 *
 * @brief The implementation of the Solution class to find the kth smallest
 * element in a BST.
 *
 * There are two solutions to solve the problem:
 * 1. Using a vector to store the inorder traversal of the BST.
 * 2. Using a recursive approach to find the kth smallest element in the BST.
 * The Solution class provides a method, kthSmallest, that takes a TreeNode
 * pointer and an integer k as input and returns the kth smallest element in the
 * BST.
 *
 * Algorithm Complexity:
 * - For both solutions, the time complexity is O(n), where n is the number of
 * nodes in the BST.
 * - For the first solution, the space complexity is O(n), where n is the number
 * of nodes in the BST. For the second solution, the space complexity is O(1).
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
class Solution1 {
   private:
	void inorder(vector<int>& ans, int& k, TreeNode* node) {
		if (!node)
			return;

		inorder(ans, k, node->left);
		ans.push_back(node->val);
		inorder(ans, k, node->right);
	}

   public:
	int kthSmallest(TreeNode* root, int k) {
		vector<int> ans;
		inorder(ans, k, root);

		return ans[k - 1];
	}
};

class Solution2 {
   private:
	void inorder(int& ans, int& k, TreeNode* node) {
		if (!node)
			return;

		inorder(ans, k, node->left);
		k--;
		if (k == 0) {
			ans = node->val;
			return;
		}
		inorder(ans, k, node->right);
	}

   public:
	int kthSmallest(TreeNode* root, int k) {
		int ans = 0;
		inorder(ans, k, root);

		return ans;
	}
};
// @lc code=end
