/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * @brief The implementation of the Solution class, which is used to return the
 * inorder traversal of a binary tree.
 *
 * Inorder means to visit the left subtree, then the root, and finally the right
 * subtree.
 * The Solution class provides a method, inorderTraversal, that takes a
 * TreeNode pointer as input and returns a vector of integers containing the
 * inorder traversal of the binary tree. The method uses a recursive approach to
 * traverse the binary tree in inorder and stores the values in a vector, which
 * is returned as the output.
 *
 * Algorithm Complexity:
 * - The inorderTraversal method has a time complexity of O(n), where n is the
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
   private:
	void inorder(vector<int>& ans, TreeNode* node) {
		if (!node)
			return;
		inorder(ans, node->left);
		ans.push_back(node->val);
		inorder(ans, node->right);
	}

   public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;

		inorder(ans, root);

		return ans;
	}
};
// @lc code=end
