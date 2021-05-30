/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flow = 1;

        for(int i=digits.size()-1; i>=0; i--)
        {
            digits[i] += flow;
            
            if(digits[i] > 9)
            {
                flow = digits[i] / 10;
                digits[i] %= 10;
            }
            else
            {
                flow = 0;
            }
        }

        if(flow)    digits.insert(digits.begin(), flow);

        return digits;
    }
};
// @lc code=end
