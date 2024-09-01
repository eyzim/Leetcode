/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * @brief The implementation of the Solution class, which is used to convert a
 * sorted linked list to a height-balanced binary search tree.
 *
 * The Solution class provides a method, sortedListToBST, that takes a ListNode
 * pointer, head, as input and returns a TreeNode pointer. The method constructs
 * a height-balanced binary search tree from the sorted linked list. It first
 * finds the middle of the linked list and cuts it into two halves. Then, it
 * recursively constructs the left and right subtrees using the two halves of
 * the linked list. Finally, it returns the root node of the binary search tree.
 *
 * Algorithm Complexity:
 * - The sortedListToBST method has a time complexity of O(n log n), where n is
 * the number of nodes in the linked list.
 * - The space complexity of the method is O(log n), where n is the number of
 * nodes in the linked list.
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
   public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head)
			return NULL;
		if (!head->next)
			return new TreeNode(head->val);

		// Find the middle of the linked list and cut it into two halves
		ListNode *slow = head, *fast = head, *cutHalf = NULL;
		while (fast && fast->next) {
			cutHalf = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		// Cut the list into two halves
		if (cutHalf)
			cutHalf->next = NULL;

		TreeNode* node = new TreeNode(slow->val);
		node->left = sortedListToBST(head);
		node->right = sortedListToBST(slow->next);

		return node;
	}
};
// @lc code=end
