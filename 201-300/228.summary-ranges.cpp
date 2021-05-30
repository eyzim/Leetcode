/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        nums.push_back(INT_MIN);

        long int start = nums[0], count = 0;
        vector<string> ans;

        for(auto i=1; i<nums.size(); i++)
        {
            if(nums[i] == start + count + 1)
            {
                count++;
            }
            else
            {
                string str = to_string(start);
                str += (count > 0) ? ("->" + to_string(nums[i-1])) : "";

                ans.push_back(str);
                
                start = nums[i];
                count = 0;                
            }
        }

        return ans;
    }
};
// @lc code=end