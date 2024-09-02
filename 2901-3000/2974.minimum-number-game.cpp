/*
 * @lc app=leetcode id=2974 lang=cpp
 *
 * [2974] Minimum Number Game
 *
 * @brief The implementation of the Solution class, which is used to find the
 * minimum number and reposition the numbers in the array.
 *
 * There are two solutions provided in the code snippet. The first solution uses
 * a priority queue to store the numbers in the array and then repositions them
 * in the array. The second solution sorts the array and then repositions the
 * numbers in the array. The second solution uses the ranges library to sort the
 * array.
 *
 * Algorithm Complexity:
 * - The time complexity of both solutions is O(n*log(n)), where n is the number
 * of elements in the array.
 * - The space complexity of the method is O(n), where n is the number of
 * elements in the array.
 */

// @lc code=start
class Solution1 {
   public:
	vector<int> numberGame(vector<int>& nums) {
		priority_queue<int, vector<int>, greater<int>> pq;

		for (auto i : nums) {
			pq.push(i);
		}

		vector<int> arr(nums.size());
		for (auto i = 1; i < arr.size(); i += 2) {
			arr[i] = pq.top();
			pq.pop();
			arr[i - 1] = pq.top();
			pq.pop();
		}

		return arr;
	}
};

class Solution2 {
   public:
	vector<int> numberGame(vector<int>& nums) {
		ranges::sort(nums);
		vector<int> arr(nums.size());

		for (auto i = 0; i < arr.size(); i += 2) {
			arr[i] = nums[i + 1];
			arr[i + 1] = nums[i];
		}

		return arr;
	}
};
// @lc code=end
