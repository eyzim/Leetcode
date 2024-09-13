/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 *
 * @brief Given the root of a binary tree, return the leftmost value in the last
 * row of the tree.
 *
 * The idea is to use a queue to traverse the binary tree level by level. At
 * each level, we update the bottomLeftValue with the value of the leftmost
 * node. Finally, we return the bottomLeftValue.
 *
 * Algorithm Complexity:
 * 1. Solution1:
 *   - Time complexity: O(n)
 *   - Space complexity: O(n)
 * 2. Solution2:
 *   - Time complexity: O(n)
 *   - Space complexity: O(1)
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
   public:
	int findBottomLeftValue(TreeNode* root) {
		if (!root)
			return 0;

		vector<int> ans;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int q_size = q.size();
			ans.clear();

			for (int i = 0; i < q_size; i++) {
				TreeNode* n = q.front();
				q.pop();
				ans.push_back(n->val);

				if (n->left)
					q.push(n->left);
				if (n->right)
					q.push(n->right);
			}
		}

		return ans[0];
	}
};

class Solution2 {
   public:
	int findBottomLeftValue(TreeNode* root) {
		if (!root)
			return 0;

		int bottomLeftValue = root->val;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int q_size = q.size();

			for (int i = 0; i < q_size; i++) {
				TreeNode* n = q.front();
				q.pop();

				// Update bottomLeftValue at the start of each level
				if (i == 0) {
					bottomLeftValue = n->val;
				}

				if (n->left)
					q.push(n->left);
				if (n->right)
					q.push(n->right);
			}
		}

		return bottomLeftValue;
	}
};
// @lc code=end
