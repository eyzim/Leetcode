/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * @brief The implementation of the Solution class, which is used to check if an
 * array contains any duplicates.
 *
 * The Solution class provides a method, containsDuplicate, that takes a vector
 * of integers as input and returns a boolean value representing whether the
 * array contains any duplicates. The method uses an unordered set to store the
 * unique elements of the array. It iterates through the array and checks if the
 * current element is already present in the set. If the element exists, the
 * method returns true. If the element does not exist, the method marks the
 * element as visited by inserting it into the set. The method returns false if
 * no duplicates are found.
 *
 * Algorithm Complexity:
 * - The containsDuplicate method has a time complexity of O(n), where n is the
 * size of the input array.
 * - The space complexity of the method is O(n), where n is the size of the
 * input array.
 */

// @lc code=start
class Solution {
   public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> mp;

		for (auto i : nums) {
			// if the number exists already
			if (mp.count(i)) {
				return true;
			}

			// if the number first exist, mark it
			mp.insert(i);
		}

		return false;
	}
};
// @lc code=end
