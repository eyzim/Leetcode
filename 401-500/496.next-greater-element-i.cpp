/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 *
 * @brief The implementation of the Solution class, which is used to find the
 * next greater element of each element in the first array in the second array.
 *
 * There are two implementations of the Solution class, Solution1 and Solution2.
 * Solution1 uses a brute-force approach to find the next greater element of
 * each element in the first array in the second array. Solution2 uses a stack
 * to find the next greater element of each element in the first array in the
 * second array.
 *
 * Algorithm Complexity:
 * 1. Solution1:
 * - Time Complexity: O(n^2), where n is the number of elements in the second
 * array.
 * - Space Complexity: O(n), where n is the number of elements in the first
 * array.
 * 2. Solution2:
 * - Time Complexity: O(n), where n is the number of elements in the second
 * array.
 * - Space Complexity: O(n), where n is the number of elements in the first
 * array.
 */

// @lc code=start
class Solution1 {
   public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		if (!nums1.size())
			return {};

		vector<int> ans(nums1.size(), -1);
		if (!nums2.size())
			return ans;

		// Create a map to store the next greater element of each element in the
		// second array.
		unordered_map<int, int> mp;
		for (int i = 0; i < nums2.size(); i++) {
			for (int j = i + 1; j < nums2.size(); j++) {
				if (nums2[i] < nums2[j]) {
					mp[nums2[i]] = nums2[j];
					break;
				}
			}
		}

		for (auto i = 0; i < nums1.size(); i++) {
			if (mp[nums1[i]])
				ans[i] = mp[nums1[i]];
		}

		return ans;
	}
};

class Solution2 {
   public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans(nums1.size(), -1);

		unordered_map<int, int> mp;
		stack<int> st;

		// Traverse the second array from right to left and store the next
		// greater element
		for (int i = nums2.size() - 1; i >= 0; i--) {
			// Pop the elements from the stack until the top element is greater
			// than the current element in the second array
			while (!st.empty() && st.top() < nums2[i]) {
				st.pop();
			}
			// Store the next greater element of the current element in the
			// second array
			if (!st.empty()) {
				mp[nums2[i]] = st.top();
			}
			// Push the current element in the second array to the stack
			st.push(nums2[i]);
		}

		for (auto i = 0; i < nums1.size(); i++) {
			if (mp[nums1[i]])
				ans[i] = mp[nums1[i]];
		}

		return ans;
	}
};
// @lc code=end
