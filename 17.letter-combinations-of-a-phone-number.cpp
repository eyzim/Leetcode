/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
private:
    vector<string> mp = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:

    vector<string> letterCombinations(string digits) {

        vector<string> ans = {""};

        for(auto i:digits)
        {
            ans = addWords(i-'0'-1, ans);
        }

        if(ans.size()==1)
        {
            return {};
        }

        return ans;
    }

    vector<string> addWords(int n, vector<string> ans) {
        
        vector<string> temp;

        for(auto i:ans) {
            for(auto j:mp[n])
            {
                temp.push_back(i+j);
            }
        }

        return temp;
    }
};
// @lc code=end