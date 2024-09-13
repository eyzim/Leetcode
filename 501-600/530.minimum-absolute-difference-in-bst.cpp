/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * @brief The implementation of the Solution class, which is used to find the
 * minimum absolute difference in a binary search tree.
 * Note that this question is the same as 783. Minimum Distance Between BST
 * Nodes
 *
 * The Solution class provides a method, getMinimumDifference, that takes a
 * TreeNode pointer, root, as input and returns the minimum absolute difference
 * in the binary search tree. First, it initializes an integer, ans, to INT_MAX
 * and a TreeNode pointer, left, to NULL. It then calls a helper function,
 * inorder, to traverse the binary search tree in inorder. The inorder function
 * takes an integer reference, ans, a TreeNode pointer reference, prev, and a
 * TreeNode pointer, node, as input and recursively traverses the left subtree,
 * checks the difference between the current node and the previous node, and
 * updates ans accordingly, and then traverses the right subtree. Finally, the
 * method returns ans.
 *
 * Algorithm Complexity:
 * - The getMinimumDifference method has a time complexity of O(n), where n is
 * the number of nodes in the binary search tree.
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
	void inorder(int& ans, TreeNode*& prev, TreeNode* node) {
		if (!node)
			return;

		inorder(ans, prev, node->left);

		// Get the minimum difference between the current node and the previous
		// node
		if (prev) {
			ans = min(ans, abs(node->val - prev->val));
		}

		// Update the previous node to the current node for the right subtree
		prev = node;
		inorder(ans, prev, node->right);
	}

   public:
	int getMinimumDifference(TreeNode* root) {
		int ans = INT_MAX;
		TreeNode* left = NULL;

		inorder(ans, left, root);

		return ans;
	}
};
// @lc code=end
