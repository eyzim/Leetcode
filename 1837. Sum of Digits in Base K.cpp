class leetcode1837 {
public:
    int sumBase(int n, int k) {
        
        auto ans=0;
        
        while(n>=k)
        {            
            ans += n%k;
            n = n/k;
        }        
        ans += n;
        
        return ans;
    }
};