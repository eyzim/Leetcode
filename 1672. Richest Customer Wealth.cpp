class leetcode1672 {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        auto richest = 0;
        
        for(auto i=0; i<accounts.size(); i++)
        {
            auto wealth = 0;
            for(auto j=0; j<accounts[i].size(); j++)
            {
                wealth += accounts[i][j];               
            }            
            if(wealth > richest)
            {
                richest = wealth;
            }
        }
        return richest;
    }
};