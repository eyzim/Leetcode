/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if( n == 0 )    return true;
        if(flowerbed.size() < n) return false;

        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);

        for(auto i=1; i<flowerbed.size()-1; i++)
        {
            cout << i ;
            if( n == 0 )    return true;
            if(!flowerbed[i-1] && !flowerbed[i] && !flowerbed[i+1]){
                n--;
                flowerbed[i] = 1;
            }
        }

        return (n == 0);
    }
};
// @lc code=end

