/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * @brief The implementation of the Solution class, which is used to return the
 * level order traversal of a binary tree.
 *
 * The Solution class provides a method, levelOrder, that takes a TreeNode
 * pointer, root, as input and returns a vector of vectors of integers
 * containing the level order traversal of the binary tree. The method uses a
 * queue to traverse the binary tree level by level and stores the values in a
 * vector of vectors, which is returned as the output.
 *
 * Algorithm Complexity:
 * - The levelOrder method has a time complexity of O(n), where n is the number
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;

		levelorder(ans, root);

		return ans;
	}
};
// @lc code=end
