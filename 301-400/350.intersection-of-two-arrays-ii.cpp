/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * @brief The implementation of the Solution class, which is used to find the
 * intersection of two arrays.
 *
 * The Solution class provides a method, intersect, that takes two vectors of
 * integers as input and returns a vector containing the intersection of the two
 * arrays. The method uses a hash map to store the frequency of each element in
 * the first array and then iterates over the second array to find the common
 * elements.
 *
 * Algorithm Complexity:
 * - The intersect method has a time complexity of O(n + m), where n and m are
 * the lengths of the input arrays.
 * - The space complexity of the intersect method is O(n), where n is the length
 * of the first input array.
 */

// @lc code=start
class Solution {
   public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> mp;
		vector<int> ans;

		// store the frequency of each element in the first array
		for (const auto i : nums1) {
			mp[i]++;
		}

		// iterate over the second array to find the common elements
		for (const auto i : nums2) {
			// if the element is present in the map, add it to the answer
			if (mp[i]) {
				ans.push_back(i);
				mp[i]--;
			}
		}

		return ans;
	}
};
// @lc code=end
