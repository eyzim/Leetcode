/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int start = newInterval[0], end = newInterval[1];

        vector<vector<int>> ans;

        for(auto i : intervals)
        {
            if(i[0]<=start && i[1]>=start && i[i]<= end)
            {
                ans.push_back([start, i[1]]);
            }
            else if(i[0]<=start && i[1]>=end)
            {
                ans.push_back(i);
            }
            else
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
// @lc code=end

