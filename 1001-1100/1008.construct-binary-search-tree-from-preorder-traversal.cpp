/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 *
 * @brief The implementation of the Solution class, which is used to construct a
 * binary search tree from a preorder traversal.
 *
 * The Solution class provides a method, bstFromPreorder, that takes a vector of
 * integers, preorder, as input and constructs a binary search tree from the
 * preorder traversal. The method initializes a TreeNode pointer, node, to NULL
 * and calls a helper function, buildNode, to construct the binary search tree.
 * The buildNode function takes the vector of integers, v, and two integers,
 * start and end, as input and recursively constructs the binary search tree. It
 * first creates a new TreeNode with the value at the start index of the vector.
 * It then finds the first element greater than the current node and recursively
 * builds the left and right subtrees. Finally, it returns the constructed node.
 *
 * Algorithm Complexity:
 * - The bstFromPreorder method has a time complexity of O(n), where n is the
 * number of nodes in the binary search tree.
 * - The space complexity of the method is O(n).
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
	TreeNode* buildNode(vector<int>& v, int start, int end) {
		if (start > end) {
			return nullptr;
		}

		TreeNode* node = new TreeNode(v[start]);

		// Find the first element greater than the current node
		int mid = start + 1;
		while (mid <= end && v[mid] < v[start]) {
			mid++;
		}

		// Recursively build the left and right subtrees
		node->left = buildNode(v, start + 1, mid - 1);
		node->right = buildNode(v, mid, end);

		return node;
	}

   public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		return buildNode(preorder, 0, preorder.size() - 1);
	}
};
// @lc code=end
