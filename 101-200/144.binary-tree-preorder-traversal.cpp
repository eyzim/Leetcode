/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * @brief The implementation of the Solution class, which is used to return the
 * preorder traversal of a binary tree.
 *
 * Preorder means to visit the root, then the left subtree, and finally the
 * right subtree.
 *
 * The Solution class provides a method, preorderTraversal, that takes a
 * TreeNode pointer as input and returns a vector of integers containing the
 * preorder traversal of the binary tree. The method uses a recursive approach
 * to traverse the binary tree in preorder and stores the values in a vector,
 * which is returned as the output.
 *
 * Algorithm Complexity:
 * - The preorderTraversal method has a time complexity of O(n), where n is the
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
	void preorder(vector<int>& ans, TreeNode* node) {
		if (!node)
			return;
		ans.push_back(node->val);
		preorder(ans, node->left);
		preorder(ans, node->right);
	}

   public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		preorder(ans, root);
		return ans;
	}
};
// @lc code=end
