/*
 * @lc app=leetcode id=1502 lang=cpp
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 */

// @lc code=start
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        if(arr.size() == 2) return 1;

        sort(arr.begin(), arr.end());

        int r = arr[1] - arr[0];
        
        for(auto i=2; i<arr.size(); i++)
        {
            if(arr[i]-arr[i-1] != r)
            {
                return 0;
            }
        }

        return 1;
    }
};
// @lc code=end

