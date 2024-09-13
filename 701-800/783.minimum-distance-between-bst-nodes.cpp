/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 *
 * @brief The implementation of the Solution class, which is used to find the
 * minimum distance between BST nodes.
 * Note that this question is the same as 530. Minimum Absolute Difference in
 * BST
 *
 * The Solution class provides a method, minDiffInBST, that takes a TreeNode
 * pointer, root, as input and returns the minimum distance between BST nodes.
 * First, it initializes an integer, ans, to INT_MAX and a TreeNode pointer,
 * prev, to NULL. It then calls a helper function, inorder, to traverse the
 * binary search tree in inorder. The inorder function takes an integer
 * reference, ans, a TreeNode pointer reference, prev, and a TreeNode pointer,
 * node, as input and recursively traverses the left subtree, checks the
 * difference between the current node and the previous node, and updates ans
 * accordingly, and then traverses the right subtree. Finally, the method
 * returns ans.
 *
 * Algorithm Complexity:
 * - The minDiffInBST method has a time complexity of O(n), where n is the
 * number of nodes in the binary search tree.
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
			ans = min((node->val - prev->val), ans);
		}

		// Update the previous node to the current node for the ri
		prev = node;
		inorder(ans, prev, node->right);
	}

   public:
	int minDiffInBST(TreeNode* root) {
		int ans = INT_MAX;
		TreeNode* prev = NULL;

		inorder(ans, prev, root);

		return ans;
	}
};
// @lc code=end
