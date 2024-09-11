/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * @brief The implementation of the Solution class, which is used to find the
 * level order traversal of a binary tree in reverse order. Note that the
 * question is similar to 102.binary-tree-level-order-traversal.cpp.
 *
 * The Solution class provides a method, levelOrderBottom, that takes a TreeNode
 * pointer, root, as input and returns a vector of vectors of integers. It
 * initializes a vector of vectors, ans, to store the level order traversal of
 * the binary tree. It then calls a helper function, bfs, to traverse the binary
 * tree in a breadth-first search manner and update the ans vector. Finally, it
 * reverses the ans vector and returns it.
 *
 * Algorithm Complexity:
 * - The levelOrderBottom method has a time complexity of O(n), where n is the
 * number of nodes in the binary tree.
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
	void levelorder(vector<vector<int>>& ans, TreeNode* node) {
		if (!node)
			return;

		// Use a queue to traverse the binary tree level by level
		queue<TreeNode*> q;
		q.push(node);

		while (!q.empty()) {
			// Store the size of this level
			int q_size = q.size();
			vector<int> level(q_size);

			// Traverse the current level and push the next level into the queue
			for (auto i = 0; i < q_size; i++) {
				TreeNode* n = q.front();
				q.pop();
				level[i] = n->val;

				if (n->left) {
					q.push(n->left);
				}
				if (n->right) {
					q.push(n->right);
				}
			}
			ans.push_back(level);
		}
	}

   public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;

		levelorder(ans, root);

		// Reverse the ans vector, as the question requires the level order
		// traversal in reverse order
		reverse(ans.begin(), ans.end());

		return ans;
	}
};
// @lc code=end
