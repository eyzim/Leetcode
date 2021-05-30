class leetcode1486 {
public:
    int xorOperation(int n, int start) {
        
        auto ans = 0;
        
        for(auto i=0; i<n; i++)
        {
            ans ^= (start + 2*i);
        }
        return ans;
    }
};