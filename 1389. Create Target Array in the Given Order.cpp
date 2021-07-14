class leetcode1389 {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans;
        
        for(auto i=0; i<nums.size(); i++)
        {
            ans.insert(ans.begin()+index[i], nums[i]);
        }
        
        return ans;
    }
};