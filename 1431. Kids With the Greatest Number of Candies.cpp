class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector <bool>ans;
        auto max= *max_element(candies.begin(), candies.end());

/*
        for(auto i=0; i<candies.size(); i++)
        {
            if(candies[i]>max)
            {
                max = candies[i];
            }
        }
*/                
        for(auto &i:candies)
        {            
                if(i + extraCandies >= max)
                    ans.push_back(true);
                else
                    ans.push_back(false);
        }
        return ans;
    }
};