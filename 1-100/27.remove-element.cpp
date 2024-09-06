/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 *
 * @brief The implementation of the Solution class, which is used to remove all
 * instances of a value in a given array.
 *
 * The first solution takes a vector of
 * integers, nums, and an integer, val, as input and removes all instances of
 * the value, val, from the array. It iterates through the array and removes the
 * elements with the value, val, by erasing the elements from the vector.
 * The second solution takes a vector of integers, nums, and an integer, val, as
 input and removes all instances of the value, val, from the array. It creates a
 new vector, ans, and copies all the elements from the input vector, nums, that
 are not equal to the value, val, to the new vector. Finally, it assigns the new
 vector, ans, to the input vector, nums, and returns the size of the new vector.
 *
 * Algorithm Complexity:
* - The time complexity of the first solution is O(n), where n is the number of
elements in the array.
* - The space complexity of the first solution is O(1).
* - The time complexity of the second solution is O(n), where n is the number of
elements in the array.
* - The space complexity of the second solution is O(n).
 */

// @lc code=start
class Solution1 {
   public:
	int removeElement(vector<int>& nums, int val) {
		for (auto i = 0; i < nums.size(); i++) {
			if (nums[i] == val) {
				nums.erase(nums.begin() + i);
				i--;
			}
		}

		return nums.size();
	}
};

class Solution2 {
   public:
	int removeElement(vector<int>& nums, int val) {
		// Create a new vector to store the elements that are not equal to val
		vector<int> ans;
		for (auto i = 0; i < nums.size(); i++) {
			if (nums[i] != val) {
				ans.push_back(nums[i]);
			}
		}

		// Assign the new vector to the input vector
		nums = ans;

		return ans.size();
	}
};
// @lc code=end
