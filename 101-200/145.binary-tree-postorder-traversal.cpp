/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * @brief The implementation of the Solution class, which is used to return the
 * postorder traversal of a binary tree.
 *
 * Postorder means to visit the left subtree, then the right subtree, and
 * finally the root.
 * The Solution class provides a method, postorderTraversal,
 * that takes a TreeNode pointer as input and returns a vector of integers
 * containing the postorder traversal of the binary tree. The method uses a
 * recursive approach to traverse the binary tree in postorder and stores the
 * values in a vector, which is returned as the output.
 *
 * Algorithm Complexity:
 * - The postorderTraversal method has a time complexity of O(n), where n is the
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
	void postorder(vector<int>& ans, TreeNode* node) {
		if (!node)
			return;
		postorder(ans, node->left);
		postorder(ans, node->right);
		ans.push_back(node->val);
	}

   public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;

		postorder(ans, root);

		return ans;
	}
};
// @lc code=end
