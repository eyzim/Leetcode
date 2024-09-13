/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 *
 * @brief The implementation of the Solution class, which is used to delete a
 * node in a linked list.
 *
 * The Solution class provides a method, deleteNode, that takes a ListNode
 * pointer, node, as input and deletes the node from the linked list. The method
 * copies the value of the next node to the current node and then deletes the
 * next node.
 *
 * Algorithm Complexity:
 * - The deleteNode method has a time complexity of O(1).
 * - The space complexity of the method is O(1).
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
	void deleteNode(ListNode* node) { *node = *node->next; }
};
// @lc code=end
