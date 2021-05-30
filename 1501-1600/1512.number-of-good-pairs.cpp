/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 *
 * @brief The implementation of the Solution class, which is used to return the
 * number of good pairs in an array.
 *
 * The Solution class provides a method, numIdenticalPairs, that takes a vector
 * of integers as input and returns the number of good pairs in the input array.
 * A good pair is defined as a pair of indices (i, j) where i < j and nums[i] ==
 * nums[j]. The method uses a hash map to store the frequency of each number in
 * the input array. It then iterates through the array and calculates the number
 * of good pairs using the frequency of each number. The total number of good
 * pairs is returned as the output.
 *
 * Algorithm Complexity:
 * - The numIdenticalPairs method has a time complexity of O(n), where n is the
 * number of elements in the input array.
 * - The space complexity of the method is O(n), where n is the number of
 * elements in the input array.
 */

// @lc code=start
class Solution {
   public:
	int numIdenticalPairs(vector<int>& nums) {
		unordered_map<int, int> mp;
		int ans = 0;

		for (auto i : nums) {
			// If the number is already present in the map, increment the count
			// of pairs by the value of the number in the map.
			if (mp[i]) {
				ans += mp[i];
			}
			mp[i]++;
		}

		return ans;
	}
};
// @lc code=end
