/*
 * @lc app=leetcode id=2471 lang=cpp
 *
 * [2471] Minimum Number of Operations to Sort a Binary Tree by Level
 *
 * @brief The implementation of the Solution class, which is used to find the
 * minimum number of operations to sort a binary tree by level.
 *
 * The Solution class provides a method, minimumOperations, that takes a
 * TreeNode pointer, root, as input and returns the minimum number of operations
 * to sort the binary tree by level. The method uses a queue to traverse the
 * binary tree level by level and stores the values in a vector, which is used
 * to calculate the number of operations needed to sort the vector.
 *
 * Algorithm Complexity:
 * - The minimumOperations method has a time complexity of O(n^2), where n is
 * the number of nodes in the binary tree.
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
	int checkSwapTimes(vector<int> v) {
		// If the vector has only one element, it is already sorted
		if (v.size() == 1)
			return 0;

		// Sort the vector and create a map to store the target index of each
		// element
		vector<int> t = v;
		sort(t.begin(), t.end());
		unordered_map<int, int> mp;
		for (auto i = 0; i < t.size(); i++) {
			mp[t[i]] = i;
		}

		// Count the number of swaps needed to sort the vector
		int count = 0;
		for (auto i = 0; i < v.size(); i++) {
			while (mp[v[i]] != i) {
				// Swap the elements to the target index
				swap(v[i], v[mp[v[i]]]);
				count++;
			}
		}

		return count;
	}

   public:
	int minimumOperations(TreeNode* root) {
		int ans = 0;
		if (!root)
			return ans;

		queue<TreeNode*> q;
		q.push(root);

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

			ans += checkSwapTimes(level);
		}

		return ans;
	}
};
// @lc code=end
