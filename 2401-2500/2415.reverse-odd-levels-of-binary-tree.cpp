/*
 * @lc app=leetcode id=2415 lang=cpp
 *
 * [2415] Reverse Odd Levels of Binary Tree
 *
 * @brief The implementation of the Solution class, which is used to reverse the
 * values of the nodes of odd levels in a binary tree.
 *
 * The Solution class provides a method, reverseOddLevels, that takes a TreeNode
 * pointer, root, as input and reverses the values of the nodes of odd levels in
 * the binary tree. First, it initializes a queue, q, and pushes the root node
 * into the queue. It then iterates over the queue until it is empty, collecting
 * the nodes of odd levels and reversing their values. Finally, it returns the
 * root node of the binary tree.
 *
 * Algorithm Complexity:
 * - The reverseOddLevels method has a time complexity of O(n), where n is the
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
	// Reverse the values of the nodes of odd levels
	void reverseVal(vector<TreeNode*>& level) {
		int start = 0, end = level.size() - 1;

		while (start < end) {
			int t = level[start]->val;
			level[start]->val = level[end]->val;
			level[end]->val = t;
			start++;
			end--;
		}
	}
	void build(TreeNode*& node) {
		if (!node)
			return;

		queue<TreeNode*> q;
		q.push(node);
		int levelCnt = 0;

		while (!q.empty()) {
			int q_size = q.size();
			vector<TreeNode*> oddLevel;

			for (int i = 0; i < q_size; i++) {
				TreeNode* n = q.front();
				q.pop();

				// collect the nodes of odd levels
				if (levelCnt % 2 == 1) {
					oddLevel.push_back(n);
				}

				if (n->left)
					q.push(n->left);
				if (n->right)
					q.push(n->right);
			}

			// reverse the values of the nodes of odd levels
			if (levelCnt % 2 == 1) {
				reverseVal(oddLevel);
			}

			levelCnt++;
		}
	}

   public:
	TreeNode* reverseOddLevels(TreeNode* root) {
		build(root);

		return root;
	}
};
// @lc code=end
