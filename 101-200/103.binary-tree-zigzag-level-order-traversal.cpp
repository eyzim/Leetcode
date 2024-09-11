/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * @brief The implementation of the Solution class, which is used to perform a
 * zigzag level order traversal of a binary tree.
 *
 * The Solution class provides a method, zigzagLevelOrder, that takes a TreeNode
 * pointer, root, as input and returns a vector of vectors of integers
 * representing the zigzag level order traversal of the binary tree. First, it
 * initializes a vector of vectors of integers, ans, and calls a helper
 * function, bfs, to perform a breadth-first search traversal of the binary
 * tree. The bfs function takes a vector of vectors of integers, ans, and a
 * TreeNode pointer, node, as input and performs a breadth-first search
 * traversal of the binary tree. It initializes a queue, q, and pushes the root
 * node into the queue. It then iterates over the queue until it is empty,
 * collecting the nodes of each level and adding them to the ans vector.
 * Finally, it reverses the values of the nodes of odd levels in the ans vector
 * and returns it.
 * Note that this problem is similar to the problem
 * 2415.reverse-odd-levels-of-binary-tree
 *
 * Algorithm Complexity:
 * - The zigzagLevelOrder method has a time complexity of O(n), where n is the
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
	// Oridinary BFS
	void bfs(vector<vector<int>>& ans, TreeNode* node) {
		if (!node)
			return;

		queue<TreeNode*> q;
		q.push(node);

		while (!q.empty()) {
			int q_size = q.size();
			vector<int> level(q_size);

			for (int i = 0; i < q_size; i++) {
				TreeNode* n = q.front();
				q.pop();

				level[i] = n->val;

				if (n->left)
					q.push(n->left);
				if (n->right)
					q.push(n->right);
			}

			ans.push_back(level);
		}
	}

   public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;

		bfs(ans, root);

		// According to the problem statement, we need to reverse the values of
		// the nodes of odd levels
		for (int i = 0; i < ans.size(); i++) {
			if (i % 2 == 1) {
				reverse(ans[i].begin(), ans[i].end());
			}
		}

		return ans;
	}
};
// @lc code=end
