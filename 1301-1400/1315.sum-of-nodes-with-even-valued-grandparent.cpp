/*
 * @lc app=leetcode id=1315 lang=cpp
 *
 * [1315] Sum of Nodes with Even-Valued Grandparent
 *
 * @brief The implementation of the Solution class, which is used to return the
 * sum of the nodes with even-valued grandparent.
 *
 * The solution1 class provides a method, sumEvenGrandparent, that takes a
 * TreeNode pointer, root, as input and returns the sum of the nodes with
 * even-valued grandparent. The method checks if the current node is even and
 * adds the value of its grandchildren to the sum variable. The method then
 * recursively calls itself for the left and right children of the current node.
 *
 * The solution2 class provides a method, sumEvenGrandparent, that takes a
 * TreeNode pointer, root, as input and returns the sum of the nodes with
 * even-valued grandparent. The method uses a helper function, dfs, that takes
 * the current node, its parent, its grandparent, and the sum variable as input.
 * The helper function checks if the grandparent is even and adds the value of
 * the current node to the sum variable. The helper function then recursively
 * calls itself for the left and right children of the current node.
 *
 * Algorithm Complexity:
 * All solutions:
 *   - The sumEvenGrandparent method has a time complexity of O(n), where n is
 * the number of nodes in the binary tree.
 *  - The space complexity of the method is O(h), where h is the height of the
 * binary tree.
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
   private:
	void dfs(int& num, TreeNode* node) {
		if (!node)
			return;

		// If the current node is even, then add the value of its grandchildren
		// to the sum variable
		if (node->val % 2 == 0) {
			if (node->left) {
				if (node->left->left) {
					num += node->left->left->val;
				}
				if (node->left->right) {
					num += node->left->right->val;
				}
			}

			if (node->right) {
				if (node->right->left) {
					num += node->right->left->val;
				}
				if (node->right->right) {
					num += node->right->right->val;
				}
			}
		}

		// Recursively call the function for the left and right children
		build(num, node->left);
		build(num, node->right);
	}

   public:
	int sumEvenGrandparent(TreeNode* root) {
		int ans = 0;

		dfs(ans, root);

		return ans;
	}
};

class Solution2 {
   private:
	void dfs(TreeNode* node,
			 TreeNode* parent,
			 TreeNode* grandparent,
			 int& sum) {
		if (!node)
			return;

		// If the grandparent is even, then add the value of the current node to
		// the sum variable
		if (grandparent && grandparent->val % 2 == 0) {
			sum += node->val;
		}

		// Move the parent and grandparent pointers one level down the tree
		dfs(node->left, node, parent, sum);
		dfs(node->right, node, parent, sum);
	}

   public:
	int sumEvenGrandparent(TreeNode* root) {
		int sum = 0;

		dfs(root, nullptr, nullptr, sum);

		return sum;
	}
};
// @lc code=end
