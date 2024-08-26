/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * @brief The implementation of the Solution class, which is used to find all
 * the root-to-leaf paths in a binary tree that sum up to a specific value.
 *
 * Given the root of a binary tree and an integer targetSum, return all
 * root-to-leaf paths where the sum of the node values in the path equals
 * targetSum. Each path should be returned as a list of the node values, not
 * node references.
 *
 * For example, if the binary tree is as follows:
 *    5
 *   / \
 *  4   8
 *     / \
 *   11  13
 *   / \
 *  7   2
 * The targetSum is 22, and the root-to-leaf paths 5 -> 8 -> 11 -> 7 and 5 -> 8
 * -> 11 -> 2 have a sum of 22.
 *
 * The Solution class provides a method, pathSum, that takes a TreeNode pointer
 * root and an integer targetSum as input and returns a vector of vectors of
 * integers representing the root-to-leaf paths that sum up to the targetSum.
 * The method uses a recursive approach to calculate the sum of the left and
 * right subtrees. The final result is then returned based on the sum of the
 * left and right subtrees.
 *
 * Algorithm Complexity:
 * - The pathSum method has a time complexity of O(n), where n is the number of
 * nodes in the binary tree.
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
	void path(vector<vector<int>>& ans,
			  vector<int> temp,
			  TreeNode* node,
			  int target) {
		if (!node)
			return;

		target -= node->val;
		temp.push_back(node->val);

		if (target == 0 && !node->left && !node->right) {
			ans.push_back(temp);
			temp = {};
		}

		path(ans, temp, node->left, target);
		path(ans, temp, node->right, target);
	}

   public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>> ans;
		path(ans, {}, root, targetSum);

		return ans;
	}
};
// @lc code=end
