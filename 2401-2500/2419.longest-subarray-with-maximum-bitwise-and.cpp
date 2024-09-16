/*
 * @lc app=leetcode id=2419 lang=cpp
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 *
 * @brief The implementation of the Solution class, which is used to find the
 * length of the longest subarray with the maximum bitwise AND.
 *
 * Solution1: The implementation of the longestSubarray method using
 * priority_queue. The method first pushes a 0 to the nums vector and
 * initializes pre to 0 and cnt to 1. It then initializes a priority_queue of
 * pairs, pq. The method then iterates through the nums vector and increments
 * cnt if the current element is equal to pre. If the current element is not
 * equal to pre, the method pushes a pair of pre and cnt to the priority_queue,
 * resets cnt to 1, and updates pre to the current element. Finally, the method
 * returns the second element of the top element of the priority_queue.
 *
 * Solution2: The implementation of the longestSubarray method using
 * max_element. The method first initializes max_val to the maximum element in
 * the nums vector and initializes max_len and current_len to 0. It then
 * iterates through the nums vector and increments current_len if the current
 * element is equal to max_val. If the current element is not equal to max_val,
 * the method resets current_len to 0. Finally, the method returns max_len.
 *
 * Algorithm Complexity:
 * 1.Solution1:
 * - The longestSubarray method has a time complexity of O(nlogn), where n is
 * the number of elements in the nums vector.
 * - The space complexity of the method is O(n).
 * 2.Solution2:
 * - The longestSubarray method has a time complexity of O(n), where n is the
 * number of elements in the nums vector.
 * - The space complexity of the method is O(1).
 */

// @lc code=start

// using priority_queue
class Solution1 {
   public:
	int longestSubarray(vector<int>& nums) {
		nums.push_back(0);
		int pre = 0, cnt = 1;
		priority_queue<pair<int, int>> pq;

		for (auto i : nums) {
			if (i == pre) {
				cnt++;
			} else {
				pq.push({pre, cnt});
				cnt = 1;
				pre = i;
			}
		}

		return pq.top().second;
	}
};

// using max_element
class Solution2 {
   public:
	int longestSubarray(vector<int>& nums) {
		int max_val = *max_element(nums.begin(), nums.end());
		int max_len = 0, current_len = 0;

		for (int num : nums) {
			if (num == max_val) {
				current_len++;
				max_len = max(max_len, current_len);
			} else {
				current_len = 0;
			}
		}

		return max_len;
	}
};
// @lc code=end
