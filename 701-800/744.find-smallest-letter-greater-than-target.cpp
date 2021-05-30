/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        if(letters.back() <= target)    return letters.front();

        int left = 0, right = letters.size()-1;

        while(left <= right)
        {
            int mid = left + ((right - left)>>1);

            if(letters[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return letters[left];
    }
};
// @lc code=end

