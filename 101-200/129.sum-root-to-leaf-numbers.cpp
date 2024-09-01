/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
	void build(TreeNode* node, vector<string>& s, string t) {
		if (!node)
			return;

		// Convert the integer value of the node to a string and append it to
		// the temp string t
		t.push_back(node->val + '0');

		// If the node is a leaf node, add the temp string to the result vector,
		// if the node is not a leaf node, then we need to traverse the left
		// and right child nodes
		if (!node->left && !node->right) {
			s.push_back(t);
		} else {
			build(node->left, s, t);
			build(node->right, s, t);
		}
	}

   public:
	int sumNumbers(TreeNode* root) {
		vector<string> s;

		build(root, s, "");

		// Convert the string to an integer and return the sum
		int ans = 0;
		for (auto i : s) {
			ans += stoi(i);
		}

		return ans;
	}
};
// @lc code=end
