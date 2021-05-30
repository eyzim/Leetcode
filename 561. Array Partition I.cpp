class leetcode561 {
public:
    int arrayPairSum(vector<int>& nums) {
        
        auto ans = 0;
        
        sort(nums.begin(), nums.end());
                    
        for(auto i=0; i<nums.size(); i=i+2)
        {
            ans += nums[i];
        }
        
        return ans;
    }
};