/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 *
 * @brief The implementation of the Solution class, which is used to calculate the
 * Hamming distance between two integers.
 *
 * The Solution1 class provides a method, hammingDistance, that takes two integers as input and returns an integer value representing the Hamming distance between the two integers. The method uses a while loop to compare the bits of the two integers. If the bits are different, the method increments the Hamming distance by 1. The method continues to compare the bits until both integers are reduced to 0.
 * The Solution2 class provides an alternative implementation of the hammingDistance method. It uses the XOR operator to find the bits that are different between the two integers. The method then counts the number of set bits in the result of the XOR operation, which represents the Hamming distance.
 *
 * Algorithm Complexity:
 * - The hammingDistance method in both Solution1 and Solution2 has a time complexity of O(log n), where n is the maximum of the two input integers.
 * - The space complexity of both methods is O(1), which does not include the space used by the output.
 */

// @lc code=start
class Solution1
{
public:
    int hammingDistance(int x, int y)
    {
        int ans = 0;

        while (x > 0 || y > 0)
        {
            if ((x % 2) != (y % 2))
            {
                ans++;
            }

            x /= 2;
            y /= 2;
        }

        return ans;
    }
};

class Solution2
{
public:
    int hammingDistance(int x, int y)
    {
        int ans = 0;
        int n = x ^ y;

        while (n)
        {
            ans++;
            n &= (n - 1);
        }

        return ans;
    }
};
// @lc code=end
