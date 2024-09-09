/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
 *
 * @brief Traverse the tree in inorder, and then reconstruct the tree in the
 * order of the inorder traversal.
 *
 * The Solution class provides a method, increasingBST, that takes a TreeNode
 * pointer, root, as input and returns a TreeNode pointer. It first initializes
 * a TreeNode pointer, ans, to a new TreeNode with a value of -1, and a TreeNode
 * pointer, cur, to ans. It then calls a helper function, inorder, to traverse
 * the binary search tree in inorder. The inorder function takes a TreeNode
 * pointer, node, as input and recursively traverses the left subtree, creates a
 * new TreeNode with the value of the current node, and sets the right child of
 * cur to the new TreeNode, and then traverses the right subtree. Finally, the
 * method returns the right child of ans.
 *
 * Algorithm Complexity:
 * Solution1:
 * - Time complexity: O(n), where n is the number of nodes in the binary search
 * tree.
 * - Space complexity: O(n), where n is the number of nodes in the binary search
 * tree. Solution2:
 * - Time complexity: O(n), where n is the number of nodes in the binary search
 * tree.
 * - Space complexity: O(n), where n is the number of nodes in the binary search
 * tree. Solution3:
 * - Time complexity: O(n), where n is the number of nodes in the binary search
 * tree.
 * - Space complexity: O(n), where n is the number of nodes in the binary search
 * tree.
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
	void inorder(TreeNode*& cur, TreeNode* node) {
		if (!node)
			return;

		inorder(cur, node->left);

		cur->right = new TreeNode(node->val);
		cur = cur->right;

		inorder(cur, node->right);
	}

   public:
	TreeNode* increasingBST(TreeNode* root) {
		// create a brand new tree
		TreeNode *ans = new TreeNode(-1), *cur = ans;

		inorder(cur, root);

		return ans->right;
	}
};

class Solution2 {
   private:
	stack<TreeNode*> st;
	void inorder(TreeNode* node) {
		if (!node)
			return;

		// Mind that this is a stack, so we need to push the right node first
		// ordinally, we should push the left node first: left->root->right
		// but in stack, we need to push the right node first: right->root->left
		inorder(node->right);
		st.push(node);
		inorder(node->left);
	}

   public:
	TreeNode* increasingBST(TreeNode* root) {
		inorder(root);

		TreeNode *cur = st.top(), *ans = cur;
		st.pop();

		while (!st.empty()) {
			cur->left = nullptr;
			cur->right = st.top();
			cur = cur->right;
			st.pop();
		}

		cur->left = nullptr;
		cur->right = nullptr;

		return ans;
	}
};

class Solution3 {
   private:
	queue<TreeNode*> q;
	void inorder(TreeNode* node) {
		if (!node)
			return;

		inorder(node->left);
		q.push(node);
		inorder(node->right);
	}

   public:
	TreeNode* increasingBST(TreeNode* root) {
		inorder(root);

		TreeNode *cur = q.front(), *ans = cur;
		q.pop();

		while (!q.empty()) {
			cur->left = nullptr;
			cur->right = q.front();
			cur = cur->right;
			q.pop();
		}

		cur->left = nullptr;
		cur->right = nullptr;

		return ans;
	}
};
// @lc code=end
