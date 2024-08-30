/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
 *
 * @brief The implementation of the Solution class, which is used to find the
 * second minimum node in a binary tree.
 *
 * The Solution class provides a method, findSecondMinimumValue, that takes a
 * TreeNode pointer as input and returns an integer value representing the
 * second minimum node in the binary tree. The method uses a preorder traversal
 * to traverse the binary tree and find the second minimum node. The method
 * initializes two variables, no1 and no2, with the maximum value of a long long
 * integer. It then traverses the binary tree and updates the values of no1 and
 * no2 based on the node values. If no2 is still equal to the maximum value
 * after the traversal, the method returns -1. Otherwise, it returns the value
 * of no2.
 *
 * Algorithm Complexity:
 * - The findSecondMinimumValue method has a time complexity of O(n), where n is
 * the number of nodes in the binary tree.
 * - The space complexity of the method is O(1), which does not include the
 * space used by the output.
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
	long long int no1, no2 = LONG_MAX;

	void preorder(TreeNode* node) {
		if (!node)
			return;

		// If the value of the current node is less than the value of no1,
		// update no2.
		if (node->val > no1 && node->val < no2) {
			no2 = node->val;
		}
		preorder(node->left);
		preorder(node->right);
	}

   public:
	int findSecondMinimumValue(TreeNode* root) {
		no1 = root->val;
		preorder(root);

		// If no2 is still equal to the maximum value after the traversal,
		// return -1.
		if (no2 == LONG_MAX) {
			return -1;
		}

		return no2;
	}
};
// @lc code=end
