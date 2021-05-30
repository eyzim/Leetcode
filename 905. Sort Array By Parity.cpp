class leetcode905 {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        vector<int> ans;
        
        for(auto no : nums)
        {
            if(no%2==0)
            {
                ans.push_back(no);
            }
        }
        
        for(auto no : nums)
        {
            if(no%2!=0)
            {
                ans.push_back(no);
            }
        }
           
            /*
            if(no%2==0)
            {
                ans.insert(ans.begin(), no);
            }                
            else
            {
                ans.insert(ans.end(), no);
            }
            */
        
        return ans;
    }
};