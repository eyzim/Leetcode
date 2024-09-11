/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
 *
 * @brief The implementation of the Solution class, which is used to merge two
 * binary trees.
 *
 * Solution1 provides a recursive solution to the problem, while Solution2 uses
 * an iterative approach.
 * The mergeTrees method takes two binary trees as input and returns a new
 * binary tree that is the result of merging the two input trees. The method
 * traverses the two input trees in a pre-order manner and merges the nodes of
 * the two trees. If a node is present in only one of the input trees, the node
 * is copied to the merged tree as is. If a node is present in both input trees,
 * the values of the two nodes are added together and stored in the merged tree.
 * The method returns the root of the merged tree.
 *
 * Algorithm Complexity:
 * 1. Solution1:
 *   - Time Complexity: O(n), where n is the number of nodes in the larger of
 * the two input trees.
 *  - Space Complexity: O(n), where n is the number of nodes in the larger of
 * the two input trees.
 * 2. Solution2:
 *  - Time Complexity: O(n), where n is the number of nodes in the larger of the
 * two input trees.
 * - Space Complexity: O(n), where n is the number of nodes in the larger of the
 * two input trees.
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
class Solution1 {
   public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		if (!root1 && !root2)
			return NULL;
		if (!root1)
			return root2;
		if (!root2)
			return root1;

		// Merge the values of the two nodes.
		root1->val += root2->val;

		// Recursively merge the left and right subtrees.
		root1->left = mergeTrees(root1->left, root2->left);
		root1->right = mergeTrees(root1->right, root2->right);

		return root1;
	}
};

class Solution2 {
   public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		if (!root1 && !root2)
			return NULL;
		if (!root1)
			return root2;
		if (!root2)
			return root1;

		// Get the head of the tree
		queue<pair<TreeNode*, TreeNode*>> q;
		q.push({root1, root2});

		while (!q.empty()) {
			auto [n1, n2] = q.front();
			q.pop();

			if (!n1 || !n2) {
				continue;
			}

			n1->val += n2->val;

			// If the left child of n1 is NULL, then we can directly assign the
			// left child of n2 to n1.
			if (!n1->left) {
				n1->left = n2->left;
			}
			// Otherwise, we need to push the left children of n1 and n2 to the
			// queue for further processing.
			else {
				q.push({n1->left, n2->left});
			}

			// Similarly, if the right child of n1 is NULL, then we can directly
			// assign the right child of n2 to n1.
			if (!n1->right) {
				n1->right = n2->right;
			}
			// Otherwise, we need to push the right children of n1 and n2 to the
			// queue for further processing.
			else {
				q.push({n1->right, n2->right});
			}
		}

		return root1;
	}
};
// @lc code=end
