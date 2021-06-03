/*
class leetcode977 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
                
        for(auto &n : nums)
        {
            n *= n;
        }
        
        sort(nums.begin(), nums.end());
        
        return nums;
    }
};
*/

class leetcode977 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int right = 0, left = nums.size()-1;
        
        vector<int> ans;
        
        while(right <= left)
        {
            if(pow(nums[right], 2) > pow(nums[left],2))
            {
                ans.push_back(pow(nums[right], 2));
                right++;
            }
            else
            {
                ans.push_back(pow(nums[left], 2));
                left--;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};