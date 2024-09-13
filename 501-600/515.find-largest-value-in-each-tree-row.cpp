/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 *
 * @brief The implementation of the Solution class, which is used to find the
 * largest value in each row of a binary tree.
 *
 * The Solution class provides a method, largestValues, that takes a TreeNode
 * pointer, root, as input and returns a vector of integers. The method
 * initializes a queue, q, and pushes the root node into the queue. It then
 * enters a while loop that continues until the queue is empty. In each
 * iteration, it initializes a variable, level, to INT_MIN and iterates over the
 * nodes in the queue. For each node, it updates the level variable with the
 * maximum value of the node's value and the current level value. It then pushes
 * the left and right children of the node into the queue if they exist.
 * Finally, it pushes the level value into the answer vector and returns the
 * vector after the loop ends.
 *
 * Algorithm Complexity:
 * - The largestValues method has a time complexity of O(n), where n is the
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
   public:
	vector<int> largestValues(TreeNode* root) {
		vector<int> ans;
		if (!root)
			return ans;

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int q_size = q.size();
			int level = INT_MIN;

			for (int i = 0; i < q_size; i++) {
				TreeNode* n = q.front();
				q.pop();

				level = max(level, n->val);

				if (n->left)
					q.emplace(n->left);
				if (n->right)
					q.emplace(n->right);
			}

			ans.push_back(level);
		}

		return ans;
	}
};
// @lc code=end
