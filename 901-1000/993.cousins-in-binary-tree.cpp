/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
	bool isCousins(TreeNode* root, int x, int y) {
		if (!root)
			return false;

		queue<pair<TreeNode*, TreeNode*>> q;
		q.push({root, new TreeNode(0)});

		while (!q.empty()) {
			int q_size = q.size();
			unordered_map<int, int> mp;

			for (int i = 0; i < q_size; i++) {
				TreeNode* n = q.front().first;
				TreeNode* parent = q.front().second;
				q.pop();
				mp[n->val] = parent->val;

				if (n->left)
					q.push({n->left, n});
				if (n->right)
					q.push({n->right, n});
			}

			if ((mp[x] != mp[y]) && mp[x] && mp[y])
				return true;
			if (mp[x] || mp[y])
				return false;
		}

		return false;
	}
};
// @lc code=end
