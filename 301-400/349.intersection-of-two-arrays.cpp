/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * @brief The implementation of the Solution class, which is used to find the
 * intersection of two arrays.
 *
 * The Solution class provides two methods, intersection, that take two vectors
 * of integers as input and return a vector of integers that contains the
 * intersection of the two arrays.
 *
 * Algorithm Complexity:
 * - The time complexity of both implementations is O(n + m), where n and m
 * are the lengths of the input arrays.
 * - The space complexity of both implementations is O(n + m).
 */

// @lc code=start
class Solution1 {
   public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> mp1, mp2;
		vector<int> ans;

		// Count the frequency of each element in both arrays
		for (auto i : nums1) {
			mp1[i]++;
		}
		for (auto i : nums2) {
			mp2[i]++;
		}

		// Iterate through the first map and check if the element is present in
		// the second map
		for (const auto i : mp1) {
			if (mp2[i.first])
				ans.push_back(i.first);
		}

		return ans;
	}
};

class Solution2 {
   public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		// Create a set from nums1
		unordered_set<int> mp(nums1.begin(), nums1.end());

		// Create a vector to store the intersection elements
		vector<int> ans;
		// Reserve the minimum size of the two vectors
		ans.reserve(min(nums1.size(), nums2.size()));

		// Iterate through nums2 and check if the element is present in the set
		for (const auto i : nums2) {
			// If the element is present in the set, erase it and add it to the
			// answer vector
			if (mp.erase(i)) {
				ans.push_back(i);
			}
		}

		return ans;
	}
};
// @lc code=end
