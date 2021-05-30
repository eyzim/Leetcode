/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 *
 * @brief The implementation of the Solution class, which is used to count the
 * number of elements smaller than the current element in the given array.
 *
 * The Solution class provides a method, smallerNumbersThanCurrent, that takes
 * an array of integers as input and returns an array of integers where each
 * element represents the number of elements smaller than the current element in
 * the input array.
 * First, the input array is sorted, and a map is created to store the index of
 * each element in the sorted array. Then, the number of elements smaller than
 * the current element is calculated using the map. Finally, the result is
 * returned.
 *
 * Algorithm Complexity:
 * - The time complexity of the smallerNumbersThanCurrent method is O(nlogn),
 * where n is the length of the input array.
 * - The space complexity of the smallerNumbersThanCurrent method is O(n).
 */

// @lc code=start
class Solution {
   public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> sorted = nums;
		sort(sorted.begin(), sorted.end());

		unordered_map<int, int> mp;
		for (auto i = 0; i < sorted.size(); i++) {
			if (mp.find(sorted[i]) == mp.end()) {
				mp[sorted[i]] = i;
			}
		}

		vector<int> ans(nums.size(), 0);
		for (auto i = 0; i < nums.size(); i++) {
			ans[i] = mp[nums[i]];
		}

		return ans;
	}
};
// @lc code=end
