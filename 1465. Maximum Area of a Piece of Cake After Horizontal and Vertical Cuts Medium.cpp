class leetcode1465 {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxh = max(horizontalCuts[0], h - horizontalCuts.back()),
            maxw = max(verticalCuts[0], w - verticalCuts.back());
        
        for (auto i = 1; i < horizontalCuts.size(); i++)
        {
            maxh = max(maxh, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        for (auto i = 1; i < verticalCuts.size(); i++)
        {
            maxw = max(maxw, verticalCuts[i] - verticalCuts[i-1]);
        }
            
        return (int)((long)maxh * maxw % 1000000007);
    }
};