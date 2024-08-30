/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * @brief The implementation of the Solution class, which is used to find the
 * diameter of a binary tree.
 *
 * The Solution class provides a method, diameterOfBinaryTree, that takes a
 * TreeNode pointer as input and returns an integer value indicating the
 * diameter of the binary tree. The diameter of a binary tree is defined as the
 * number of nodes on the longest path between any two nodes in the tree. The
 * method uses a recursive approach to calculate the depth of each node in the
 * tree. The diameter of the tree is updated whenever the sum of the depths of
 * the left and right subtrees of a node is greater than the current diameter.
 *
 * Algorithm Complexity:
 * - The diameterOfBinaryTree method has a time complexity of O(n), where n is
 * the number of nodes in the binary tree.
 * - The space complexity of the method is O(1), as it uses only a constant
 * amount of extra space.
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
	int maxi = 0;
	int depth(TreeNode* node) {
		if (!node)
			return 0;

		int left = depth(node->left);
		int right = depth(node->right);

		// Update the diameter of the tree if the sum of the depths of the left
		// and right subtrees is greater than the current diameter.
		maxi = max(maxi, left + right);

		// Return the depth of the current node.
		return 1 + max(left, right);
	}

   public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (!root)
			return 0;
		depth(root);

		return maxi;
	}
};
// @lc code=end
