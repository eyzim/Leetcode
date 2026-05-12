/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * @brief The implementation of the Solution class, which is used to find the single number in an array.
 *
 * The Solution class provides a method, singleNumber, that takes a vector of integers as input and returns an integer value representing the single number in the array. The method uses the XOR operator to find the single number. The XOR operator has the property that it returns 0 when two identical numbers are XORed together, and it returns the number itself when XORed with 0. Therefore, by XORing all the numbers in the array, the method effectively cancels out all the duplicate numbers and leaves only the single number.
 *
 * Algorithm Complexity:
 * - The singleNumber method has a time complexity of O(n), where n is the size of the input array.
 * - The space complexity of the method is O(1).
 *
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {

        int ans = 0;

        for (auto i : nums)
        {
            ans ^= i;
        }

        return ans;
    }
};
// @lc code=end
