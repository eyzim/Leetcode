class leetcode1295 {
public:
    int findNumbers(vector<int>& nums) 
    {
        auto evenDigitNum = 0;
        
        for(auto n:nums)
        {            
            if(countDigits(n)%2 ==0)
            {
                evenDigitNum++;
            }
        }
        return evenDigitNum;
    }
    
    int countDigits(int n)
    {
        return floor(log10(n)+1);
    }
};