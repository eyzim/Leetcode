/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
 *
 * @brief The implementation of the Solution class, which is used to find the
 * sum of the deepest leaves of a binary tree.
 *
 * The Solution class provides a method, deepestLeavesSum, that takes a TreeNode
 * pointer, root, as input and returns the sum of the deepest leaves of the
 * binary tree. The method initializes an integer, ans, to 0 and calls a helper
 * function, bfs, to traverse the binary tree in a breadth-first search manner.
 * The bfs function takes a reference to an integer, ans, and a TreeNode
 * pointer, node, as input and traverses the binary tree level by level. It uses
 * a queue to store the nodes at each level and calculates the sum of the nodes
 * at the deepest level. Finally, the method returns the sum of the deepest
 * leaves.
 *
 * Algorithm Complexity:
 * - The deepestLeavesSum method has a time complexity of O(n), where n is the
 * number of nodes in the binary tree.
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
	void bfs(int& ans, TreeNode* node) {
		if (!node)
			return;

		queue<TreeNode*> q;
		q.push(node);

		while (!q.empty()) {
			int q_size = q.size();
			// Reset the level sum for each level
			int levelSum = 0;

			for (int i = 0; i < q_size; i++) {
				TreeNode* n = q.front();
				q.pop();
				levelSum += n->val;

				if (n->left)
					q.push(n->left);
				if (n->right)
					q.push(n->right);
			}
			// Update the sum of the deepest leaves at the current level
			ans = levelSum;
		}
	}

   public:
	int deepestLeavesSum(TreeNode* root) {
		int ans = 0;

		bfs(ans, root);

		return ans;
	}
};
// @lc code=end
