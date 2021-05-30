/*
 * @lc app=leetcode id=2248 lang=cpp
 *
 * [2248] Intersection of Multiple Arrays
 *
 * @brief The implementation of the Solution class, which is used to find the
 * intersection of multiple arrays.
 *
 * The Solution class provides two methods, compareTwo and intersection, that
 * are used to find the intersection of multiple arrays. The compareTwo method
 * is a private helper function that compares two arrays and returns the
 * intersection of the two arrays. The intersection method takes a vector of
 * vectors as input and returns the intersection of all the arrays in the input
 * vector.
 *
 * Algorithm Complexity:
 * - The compareTwo method has a time complexity of O(n), where n is the length
 * of the input arrays.
 * - The intersection method has a time complexity of O(n*m), where n is the
 * number of arrays in the input vector and m is the length of the longest
 * array.
 * - The space complexity of both methods is O(n).
 */

// @lc code=start
class Solution1 {
   private:
	vector<int> compareTwo(vector<int> n1, vector<int> n2) {
		unordered_map<int, int> mp;
		vector<int> in;

		for (const auto i : n1) {
			mp[i]++;
		}

		for (const auto i : n2) {
			if (mp[i]) {
				in.push_back(i);
				mp[i]--;
			}
		}

		return in;
	}

   public:
	vector<int> intersection(vector<vector<int>>& nums) {
		vector<int> ans = nums[0];

		for (auto i = 1; i < nums.size(); i++) {
			ans = compareTwo(ans, nums[i]);
		}

		sort(ans.begin(), ans.end());

		return ans;
	}
};

class Solution2 {
   public:
	vector<int> intersection(vector<vector<int>>& nums) {
		vector<int> ans;
		unordered_map<int, int> mp;

		for (auto i = 0; i < nums.size(); i++) {
			for (auto j = 0; j < nums[i].size(); j++) {
				mp[nums[i][j]]++;
				if (mp[nums[i][j]] == nums.size()) {
					ans.push_back(nums[i][j]);
				}
			}
		}

		sort(ans.begin(), ans.end());

		return ans;
	}
};
// @lc code=end
