/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * @brief The implementation of the Solution class, which is used to return all
 * root-to-leaf paths in a binary tree.
 *
 * Given the root of a binary tree, return all root-to-leaf paths in any order.
 * A leaf is a node with no children.
 * The Solution class provides a method, binaryTreePaths, that takes a TreeNode
 * pointer root as input and returns a vector of strings containing all
 * root-to-leaf paths in the binary tree. The method uses a recursive approach
 * to traverse the binary tree and construct the paths. The final result is then
 * returned as a vector of strings.
 *
 * Algorithm Complexity:
 * - The binaryTreePaths method has a time complexity of O(n), where n is the
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
	void checkPath(vector<string>& s, string temp, TreeNode* node) {
		if (!node)
			return;

		// Convert the integer value of the node to a string and append it to
		// the temp string
		temp += to_string(node->val);

		// If the node is a leaf node, add the temp string to the result vector
		if (!node->left && !node->right) {
			s.push_back(temp);
		} else {
			temp += "->";
			checkPath(s, temp, node->left);
			checkPath(s, temp, node->right);
		}
	}

   public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ans;

		checkPath(ans, "", root);

		return ans;
	}
};
// @lc code=end
