/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 *
 * @brief The implementation of the Solution class, which is used to split a
 * linked list into k parts.
 *
 * The Solution class provides a method, splitListToParts, that takes a ListNode
 * pointer, head, and an integer, k, as input and returns a vector of ListNode
 * pointers. The method first counts the total number of nodes in the linked
 * list and then calculates the size of each part. It then distributes the
 * linked list nodes into k parts and returns the vector of ListNode pointers.
 *
 * Algorithm Complexity:
 * - The splitListToParts method has a time complexity of O(n), where n is the
 * number of nodes in the linked list.
 * - The space complexity of the method is O(k), where k is the number of parts.
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution1 {
   public:
	vector<ListNode*> splitListToParts(ListNode* head, int k) {
		vector<ListNode*> ans(k);
		if (!head)
			return ans;

		// count total size of the linked list
		ListNode* cur = head;
		int total = 0;
		while (cur) {
			cur = cur->next;
			total++;
		}

		// count the size of each slice
		vector<int> s(k, floor(total / k));
		int remain = total % k;
		for (auto i = 0; i < s.size() && remain > 0; i++) {
			s[i]++;
			remain--;
		}

		// cut the slice by the number we stored before
		cur = head;
		for (auto i = 0; i < s.size() && cur; i++) {
			ans[i] = cur;

			for (int j = 1; j < s[i]; j++) {
				cur = cur->next;
			}
			ListNode* next = cur->next;
			cur->next = nullptr;
			cur = next;
		}

		return ans;
	}
};

class Solution2 {
   public:
	vector<ListNode*> splitListToParts(ListNode* head, int k) {
		vector<ListNode*> ans(k);
		if (!head)
			return ans;

		// count total number of the linkedlist
		ListNode* cur = head;
		int total = 0;
		while (cur) {
			cur = cur->next;
			total++;
		}

		// calculate the size of each part of the slice
		int remain = total % k;
		int per = total / k;

		// distribute the linkedlist head into the vector
		cur = head;
		for (int i = 0; i < k && cur; i++) {
			ans[i] = cur;

			// calculate the size of the current part
			int perSize = per + (remain > 0 ? 1 : 0);
			remain--;

			// move cur pointer to the end of the current part
			for (int j = 1; j < perSize; j++) {
				cur = cur->next;
			}

			// cut the current part from the next part
			ListNode* next = cur->next;
			cur->next = nullptr;
			cur = next;
		}

		return ans;
	}
};
// @lc code=end
