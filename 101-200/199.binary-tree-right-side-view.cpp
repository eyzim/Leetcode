/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * @brief The implementation of the Solution class, which is used to return the
 * right side view of a binary tree.
 *
 * In solution 1, the Solution class provides a method, rightSideView, that
 * takes a TreeNode pointer, root, as input and returns a vector of integers
 * containing the right side view of the binary tree. The method uses a
 * breadth-first search (BFS) approach to traverse the binary tree level by
 * level and stores the rightmost node of each level in the output vector. In
 * solution 2, the Solution class provides a method, rightSideView, that takes a
 * TreeNode pointer, root, as input and returns a vector of integers containing
 * the right side view of the binary tree. The method uses a depth-first search
 * (DFS) approach to traverse the binary tree and stores the rightmost node of
 * each level in the output vector.
 *
 * Algorithm Complexity:
 * All Solutions
 * - The rightSideView method has a time complexity of O(n), where n is the
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

// BFS
class Solution1 {
   public:
	vector<int> rightSideView(TreeNode* root) {
		if (!root)
			return {};

		vector<int> ans;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int q_size = q.size();

			for (int i = 0; i < q_size; i++) {
				TreeNode* n = q.front();
				q.pop();

				// If it is the last node in the current level, add it to the
				// answer.
				if (i == q_size - 1) {
					ans.push_back(n->val);
				}

				if (n->left)
					q.push(n->left);
				if (n->right)
					q.push(n->right);
			}
		}

		return ans;
	}
};

// DFS
class Solution2 {
   private:
	void dfs(vector<int>& ans, int level, TreeNode* node) {
		if (!node)
			return;

		if (level == ans.size()) {
			ans.push_back(node->val);
		}

		// Traverse the right subtree first to get the rightmost node.
		// Otherwise, the leftmost node will be added to the answer.
		dfs(ans, level + 1, node->right);
		dfs(ans, level + 1, node->left);
	}

   public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ans;

		dfs(ans, 0, root);

		return ans;
	}
};
// @lc code=end
