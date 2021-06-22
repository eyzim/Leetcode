class leetcode1089 {
public:
    void duplicateZeros(vector<int>& arr) {
                
        for(auto i=0; i<arr.size(); i++)
        {
            if(arr[i]==0)
            {
                arr.insert(i+arr.begin(), 0);
                arr.pop_back();
                i++;
            }
        }
    }
};