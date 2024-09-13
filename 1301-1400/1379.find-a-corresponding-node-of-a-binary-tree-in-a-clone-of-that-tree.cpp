/*
 * @lc app=leetcode id=1379 lang=cpp
 *
 * [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 *
 * @brief The implementation of the Solution class, which is used to find a
 * corresponding node of a binary tree in a clone of that tree.
 *
 * The Solution class provides a method, getTargetCopy, that takes three
 * TreeNode pointers, original, cloned, and target, as input and returns the
 * corresponding node of the target node in the cloned tree. The method
 * initializes a TreeNode pointer, ans, to NULL and calls a helper function,
 * dfs, to traverse the original and cloned trees. The dfs function takes the
 * original, cloned, target, and ans TreeNode pointers as input and recursively
 * traverses the trees. If the original node is NULL or the answer is already
 * found, the function returns. If the original node is equal to the target
 * node, the function sets the answer to the cloned node. The function then
 * recursively calls itself on the left and right subtrees of the original and
 * cloned trees. Finally, the method returns the answer.
 *
 * Algorithm Complexity:
 * - The getTargetCopy method has a time complexity of O(n), where n is the
 * number of nodes in the binary tree.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
   private:
	void dfs(TreeNode* original,
			 TreeNode* cloned,
			 TreeNode* target,
			 TreeNode*& ans) {
		// If the original node is NULL or the answer is already found, return.
		if (!original || ans)
			return;

		if (original == target) {
			ans = cloned;
		}

		dfs(original->left, cloned->left, target, ans);
		dfs(original->right, cloned->right, target, ans);
	}

   public:
	TreeNode* getTargetCopy(TreeNode* original,
							TreeNode* cloned,
							TreeNode* target) {
		TreeNode* ans = nullptr;

		dfs(original, cloned, target, ans);

		return ans;
	}
};
// @lc code=end
