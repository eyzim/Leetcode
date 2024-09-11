/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 *
 * @brief The implementation of the Solution class, which is used to find the
 * level with the maximum sum in a binary tree.
 *
 * The Solution class provides a method, maxLevelSum, that takes a TreeNode
 * pointer, root, as input and returns the level with the maximum sum. The
 * method initializes a priority queue, pq, with a min heap of pairs of
 * integers. It then initializes a queue, q, with the root node and a level
 * order of 1. The method traverses the binary tree in level order and
 * calculates the sum of each level. The sum and level are pushed into the min
 * heap. The method returns the level with the maximum sum. If there are
 * multiple levels with the same maximum sum, the method returns the first level
 * encountered.
 *
 * Algorithm Complexity:
 * - The maxLevelSum method has a time complexity of O(n), where n is the number
 * of nodes in the binary tree.
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
   public:
	int maxLevelSum(TreeNode* root) {
		if (!root)
			return 0;

		// Store the sum and level of each level in a min heap
		priority_queue<pair<int, int>, vector<pair<int, int>>,
					   greater<pair<int, int>>>
			pq;
		queue<TreeNode*> q;
		q.push(root);
		int levelOrder = 1;

		while (!q.empty()) {
			int q_size = q.size();
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

			// Push the level sum and level order in the min heap
			// There is a trick here, we push the negative of the level sum to
			// the min heap, so that the min heap will return the maximum level
			// sum and make the first pushed level order as the answer
			pq.push({-levelSum, levelOrder});
			levelOrder++;
		}

		return pq.top().second;
	}
};
// @lc code=end
