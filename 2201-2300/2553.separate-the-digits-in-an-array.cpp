/*
 * @lc app=leetcode id=2553 lang=cpp
 *
 * [2553] Separate the Digits in an Array
 *
 * @brief The implementation of the Solution class, which is used to separate the digits in an array.
 *
 * The Solution class provides two methods, separateDigits and separateDigits2, that are used to separate the digits in an array. The separateDigits method takes a vector of strings as input and returns a vector of integers that contains the separated digits. The separateDigits2 method takes a vector of integers as input and returns a vector of integers that contains the separated digits. Both methods iterate through the input vector and separate the digits by converting the integers to strings and then back to integers.
 *
 * Algorithm Complexity:
 * - The separateDigits method has a time complexity of O(n*m), where n is the number of integers in the input vector and m is the number of digits in the largest integer.
 * - The separateDigits2 method has a time complexity of O(n*m), where n is the number of integers in the input vector and m is the number of digits in the largest integer.
 * - The space complexity of both methods is O(n*m), where n is the number of integers in the input vector and m is the number of digits in the largest integer.
 */

// @lc code=start
class Solution1
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> ans;

        for (auto i : nums)
        {
            string n = to_string(i);

            for (auto j : n)
            {
                ans.push_back(j - '0');
            }
        }

        return ans;
    }
};

class Solution2
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        int i = nums.size() - 1;

        while (i >= 0)
        {
            while (nums[i] > 9)
            {
                nums.insert(nums.begin() + i + 1, nums[i] % 10);
                nums[i] /= 10;
            }
            i--;
        }

        return nums;
    }
};
// @lc code=end
