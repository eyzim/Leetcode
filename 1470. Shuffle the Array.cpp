class leetcode1470 {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
                
        vector<int> ans;
        
        for(auto i=0; i<n; i++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[n+i]);
        }
        return ans;
    }
};