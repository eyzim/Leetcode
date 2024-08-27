/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * @brief The implementation of the Solution class, which is used to flatten a
 * binary tree into a linked list.
 *
 * Given the root of a binary tree, flatten the tree into a "linked list":
 * - The "linked list" should use the same TreeNode class where the right child
 * pointer points to the next node in the list and the left child pointer is
 * always null.
 * - The "linked list" should be in the same order as a pre-order traversal of
 * the binary tree.
 *
 * The first solution uses a recursive approach to flatten the binary tree. The
 * method, flatten, takes a TreeNode pointer root as input and returns void. The
 * method first checks if the root is null. If the root is not null, the method
 * stores the right subtree in a variable r. It then moves the left subtree to
 * the right and sets the left pointer to null. The method then finds the
 * rightmost node of the left subtree and attaches the right subtree to it.
 * Finally, the method recursively flattens the right subtree.
 * The second solution uses a reverse preorder traversal to flatten the binary
 * tree. The method, flattenTree, takes a reference to a TreeNode pointer pre
 * and a TreeNode pointer node as input and returns void. The method first
 * checks if the node is null. If the node is not null, the method recursively
 * flattens the right subtree, then the left subtree, and finally sets the right
 * pointer of the node to the pre pointer. The pre pointer is then updated to
 * the current node. The flatten method initializes a TreeNode pointer temp to
 * null and calls the flattenTree method with temp and the root of the binary
 * tree.
 *
 * Algorithm Complexity:
 * - Both of the solutions have a time complexity of O(n), where n is the number
 * of nodes in the binary tree.
 * - The space complexity of the method is O(1), where n is the number of nodes
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
class Solution1 {
   public:
	void flatten(TreeNode* root) {
		if (!root)
			return;

		// Store the right subtree
		TreeNode* r = root->right;

		// Move the left subtree to the right
		root->right = root->left;
		root->left = NULL;

		// Find the rightmost node of the left subtree, then attach the right
		// subtree
		TreeNode* l = root;
		while (l->right) {
			l = l->right;
		}
		l->right = r;

		// Flatten the right subtree
		flatten(root->right);

		return;
	}
};

class Solution2 {
   private:
	// reverse the preorder traversal
	// traditional preorder traversal is root->left->right
	// reverse preorder traversal is right->left->root
	void flattenTree(TreeNode*& pre, TreeNode* node) {
		if (!node)
			return;

		flattenTree(pre, node->right);
		flattenTree(pre, node->left);

		node->right = pre;
		node->left = NULL;
		pre = node;
	}

   public:
	void flatten(TreeNode* root) {
		TreeNode* temp = NULL;
		return flattenTree(temp, root);
	}
};
// @lc code=end
