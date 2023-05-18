/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int c0 = 0, c1 = 0, c2 = 0;

        for(auto i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)    c0++;
            else if(nums[i]==1)    c1++;
            else    c2++;
        }

        for(auto i=0; i<nums.size(); i++)
        {
            if(i < c0) nums[i] = 0;
            else if(i < c0 + c1) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int c0=0, c1=0, c2=nums.size()-1;

        while( c1 <= c2 )
        {
            if(nums[c1] == 0)
            {
                swap(nums[c0], nums[c1]);
                c0++;
                c1++;
            }
            else if(nums[c1] == 1)
            {
                c1++;
            }
            else
            {
                swap(nums[c1], nums[c2]);
                c2--;
            }
        }
    }
};
// @lc code=end
