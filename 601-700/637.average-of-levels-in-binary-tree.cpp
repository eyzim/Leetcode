/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 *
 * @brief The implementation of the Solution class, which is used to find the
 * average of levels in a binary tree.
 *
 * The Solution1 class provides a method, averageOfLevels, that takes a TreeNode
 * pointer, root, as input and returns a vector of doubles. It initializes a
 * vector of pairs, count, to store the sum and count of nodes at each level. It
 * then calls a helper function, dfs, to traverse the binary tree and update the
 * count vector. Finally, it converts the count vector to the average and
 * returns it. The Solution2 class provides a method, averageOfLevels, that
 * takes a TreeNode pointer, root, as input and returns a vector of doubles. It
 * uses a queue to store the nodes at each level and calculates the sum of the
 * nodes at each level. Finally, it returns the average of the nodes at each
 * level.
 *
 * Algorithm Complexity:
 * 1. Solution1:
 *   - The averageOfLevels method has a time complexity of O(n), where n is the
 * number of nodes in the binary tree.
 *  - The space complexity of the method is O(h), where h is the height of the
 * binary tree.
 * 2. Solution2:
 *  - The averageOfLevels method has a time complexity of O(n), where n is the
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
class Solution1 {
   private:
	vector<pair<long, int>> count;

	void dfs(TreeNode* node, int depth) {
		if (!node)
			return;

		int v = node->val;
		// If the depth is greater than the size of the count vector, add a new
		// pair to the vector.
		if (count.size() <= depth) {
			count.push_back({v, 1});
		} else {
			// Otherwise, update the existing pair.
			count[depth].first += v;
			count[depth].second++;
		}

		// Traverse the left and right children nodes.
		dfs(node->left, depth + 1);
		dfs(node->right, depth + 1);
	}

   public:
	vector<double> averageOfLevels(TreeNode* root) {
		dfs(root, 0);

		// Convert the count to the average.
		vector<double> ans;
		for (int i = 0; i < count.size(); i++) {
			ans.push_back((double)count[i].first / count[i].second);
		}

		return ans;
	}
};

class Solution2 {
   private:
	void bfs(TreeNode* node, vector<double>& ans) {
		if (!node)
			return;

		// Use a queue to store the nodes at each level.
		queue<TreeNode*> q;
		q.push(node);

		while (!q.empty()) {
			// Later, we will go through all the nodes in the queue and
			// calculate the sum, and then push the children nodes into the
			// queue.
			int q_size = q.size();
			long sum = 0;

			for (int i = 0; i < q_size; i++) {
				// Sum up the values of the nodes at the current level.
				TreeNode* n = q.front();
				q.pop();
				sum += n->val;

				// Push the children nodes into the queue.
				if (n->left)
					q.push(n->left);
				if (n->right)
					q.push(n->right);
			}

			ans.push_back((double)sum / q_size);
		}
	}

   public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> ans;

		bfs(root, ans);

		return ans;
	}
};
// @lc code=end
