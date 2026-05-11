/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * @brief The implementation of the Solution class, which is used to find the
 * longest common prefix among a list of strings.
 *
 * The Solution class provides a method longestCommonPrefix that takes a vector of strings as input and returns the longest common prefix among the strings in the input vector. The method iterates through the strings in the input vector and compares each string with the current longest common prefix. If a mismatch is found, the longest common prefix is updated to the substring that matches up to the point of the mismatch.
 *
 * Algorithm Complexity:
 * - The longestCommonPrefix method has a time complexity of O(n*m), where n is the number of strings in the input vector and m is the length of the longest common prefix.
 * - The space complexity of the longestCommonPrefix method is O(1) if we do not consider the space used for the input and output strings, otherwise it is O(m) where m is the length of the longest common prefix.
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            for (auto j = 0; j < ans.size(); j++)
            {
                if (strs[i][j] != ans[j])
                {
                    ans = ans.substr(0, j);
                }
            }
        }

        return ans;
    }
};
// @lc code=end
