class leetcode922 {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        vector<int> odd, even, ans;
        
        for(auto n : nums)
        {
            if(n%2==0)
            {
                odd.push_back(n);
            }
            else
            {
                even.push_back(n);
            }
        }
        
        for(auto i=0; i<odd.size(); i++)
        {
            ans.push_back(odd[i]);            
            ans.push_back(even[i]);
        }
        
        return ans;
    }
};