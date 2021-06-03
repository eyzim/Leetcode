class leetcode485 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        auto temp=0, max=0;
        
        for(auto n : nums)
        {
            if(n==1)
            {
                temp++;
                if(temp>max)
                {
                    max=temp;
                }
            }
            else
            {
                temp=0;
            }
        }
        return max;
    }
};