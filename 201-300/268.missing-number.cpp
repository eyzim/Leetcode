/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * @brief Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 *
 * The solution1 class implements a straightforward approach by first sorting the input array and then checking for the missing number. The time complexity of this approach is O(n log n) due to the sorting step, and the space complexity is O(1) if we ignore the space used by the sorting algorithm.
 * The solution2 class implements a more efficient approach using the XOR operation. By XORing all the numbers in the input array with their corresponding indices, we can effectively cancel out all the numbers that are present, leaving us with the missing number. The time complexity of this approach is O(n) and the space complexity is O(1).
 *
 * Algorithm Complexity:
 * - The missingNumber method in Solution1 has a time complexity of O(n log n) and a space complexity of O(1).
 * - The missingNumber method in Solution2 has a time complexity of O(n) and a space complexity of O(1).
 */

// @lc code=start
class Solution1
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        // Check if the first number is not 0, which means 0 is missing
        if (nums[0] != 0)
            return 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] - nums[i] != 1)
            {
                return nums[i] + 1;
            }
        }

        // If all numbers are present, then the missing number is n
        return nums.size();
    }
};

class Solution2
{
public:
    int missingNumber(vector<int> &nums)
    {

        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i];
            ans ^= i;
        }

        return ans;
    }
};
// @lc code=end
