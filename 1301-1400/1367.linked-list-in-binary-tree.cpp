/*
 * @lc app=leetcode id=1367 lang=cpp
 *
 * [1367] Linked List in Binary Tree
 *
 * @brief Find if the linked list is a subpath of the binary tree
 *
 * If the current node is the start of the path, then we need to check the left
 * and right subtrees for the rest of the path in the linked list. If the
 * current node is not the start of the path, then we need to check the left and
 * right subtrees.
 * If the linked list is empty, then it is a subpath of the binary tree.
 * Otherwise, if the binary tree is empty, then the linked list is not a subpath
 * of the binary tree.
 *
 * Algorithm Complexity:
 * Time complexity : O(n * m) where n is the number of nodes in the binary tree
 * and m is the number of nodes in the linked list. Space complexity : O(n)
 * where n is the number of nodes in the binary tree.
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
	bool inorder(ListNode* list, TreeNode* tree) {
		if (!list)
			return true;
		if (!tree)
			return false;
		if (tree->val != list->val)
			return false;

		// If the current node is the start of the path, then we need to check
		// the left and right subtrees for the rest of the path in the linked
		// list
		return inorder(list->next, tree->left) ||
			   inorder(list->next, tree->right);
	}

   public:
	bool isSubPath(ListNode* head, TreeNode* root) {
		if (!head)
			return true;
		if (!root)
			return false;
		if (inorder(head, root))
			return true;

		// If the current node is not the start of the path, then we need to
		// check the left and right subtrees
		return isSubPath(head, root->left) || isSubPath(head, root->right);
	}
};
// @lc code=end
