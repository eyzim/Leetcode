/*
 * @lc app=leetcode id=3217 lang=cpp
 *
 * [3217] Delete Nodes From Linked List Present in Array
 *
 * @brief If the value of a node is present in the array, then delete that node.
 *
 * The solution is to create a set of all the elements in the array, then
 * iterate through the linked list, if the next element is present in the set,
 * then delete it. First, create a dummy node and point it to the head, so that
 * we can delete the head if needed. Then create a pointer to the dummy node.
 * Iterate through the linked list, if the next element is present in the set,
 * then delete it. If the next element is not present in the set, then move the
 * pointer to the next element.
 *
 * Algorithm Complexity:
 * - Time: O(n), where n is the number of elements in the linked list.
 * - Space: O(m), where m is the number of elements in the array.
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
class Solution {
   public:
	ListNode* modifiedList(vector<int>& nums, ListNode* head) {
		// Create a set of all the elements in the array
		unordered_set<int> mp(nums.begin(), nums.end());

		// Create a dummy node and point it to the head, so that we can delete
		// the head if needed
		ListNode prev;
		prev.next = head;

		// Create a pointer to the dummy node
		ListNode* cur = &prev;
		// Iterate through the linked list, if the next element is present in
		// the map, then delete it
		while (cur && cur->next) {
			if (mp.count(cur->next->val)) {
				cur->next = cur->next->next;
			} else {
				cur = cur->next;
			}
		}

		return prev->next;
	}
};
// @lc code=end
