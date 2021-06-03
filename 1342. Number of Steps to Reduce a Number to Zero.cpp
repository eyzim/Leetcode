class leetcode1342 {
public:
    int numberOfSteps(int num) 
    {
        auto count=0;
        
        while(num>0)
        {
            if(num%2 > 0)
            {
                num--;
            }
            else
            {
                num>>=1;                
            }
            count++;
        }
        return count;
    }
};