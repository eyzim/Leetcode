/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * @brief The implementation of the Solution class, which is used to construct a
 * binary tree from its preorder and inorder traversal.
 *
 * The Solution class provides a method, buildTree, that takes two vectors of
 * integers, preorder and inorder, as input and returns a TreeNode pointer.
 * First, the method stores the inorder traversal in a map for quick access.
 * Then, it calls a helper function, build, to construct the binary tree
 * recursively. The build function takes the preorder and inorder vectors, along
 * with the start and end indices of the current subtree, as input. It
 * constructs the root node using the first element of the preorder vector and
 * finds the position of the root node in the inorder traversal. It then
 * calculates the size of the left and right subtrees and recursively constructs
 * the left and right subtrees. Finally, it returns the root node of the binary
 * tree.
 *
 * Algorithm Complexity:
 * - The buildTree method has a time complexity of O(n), where n is the number
 * of nodes in the binary tree.
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
	unordered_map<int, int> mp;
	int findPos(int target) { return mp[target]; }

	TreeNode* build(vector<int>& pre,
					int p_start,
					int p_end,
					vector<int>& in,
					int i_start,
					int i_end) {
		if (p_start > p_end || i_start > i_end)
			return NULL;

		TreeNode* node = new TreeNode();
		node->val = pre[p_start];

		// Find the position of the root node in the inorder traversal
		// which will help us to find the size of left and right subtree
		int pos = findPos(pre[p_start]);
		// pos - i_start is the size of left subtree
		int left_size = pos - i_start;

		node->left =
			build(pre, p_start + 1, p_start + left_size, in, i_start, pos - 1);

		node->right =
			build(pre, p_start + left_size + 1, p_end, in, pos + 1, i_end);

		return node;
	}

   public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (!preorder.size() || !inorder.size()) {
			return NULL;
		}

		// Store the inorder traversal in a map for quick access
		for (auto i = 0; i < inorder.size(); i++) {
			mp[inorder[i]] = i;
		}

		return build(preorder, 0, preorder.size() - 1, inorder, 0,
					 inorder.size() - 1);
	}
};
// @lc code=end
