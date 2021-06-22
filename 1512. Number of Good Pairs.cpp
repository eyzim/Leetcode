class leetcode1512 {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int ans=0;
        vector<int> count(101, 0);
        
        for(auto n:nums)
        {
            count[n]++;
        }
        
        for(auto n:count)
        {
            ans += (n*(n-1))/2;       
        }
                    
        return ans;
    }
};