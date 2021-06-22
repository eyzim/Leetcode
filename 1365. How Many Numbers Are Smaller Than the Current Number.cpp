class leetcode1365 {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> temp = nums;
        vector<int> ans;
        
        sort(temp.begin(), temp.end());
        
        for(auto i=0; i<nums.size(); i++)
        {
            auto j=0;
            while(nums[i]>temp[j])
            {
                j++;
            }
            ans.push_back(j);
        }
        
        return ans;
    }
};