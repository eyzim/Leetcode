/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string s2 = "", t2 = "";
        int cs = 0, ct = 0;

        for(int i=t.size()-1; i>=0; i--)
        {
            if(t[i] == '#')
            {
                ct++;
            }
            else if(ct)
            {
                ct--;
            }
            else
            {
                t2 += t[i];
            }
        }

        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i] == '#')
            {
                cs++;
            }
            else if(cs)
            {
                cs--;
            }
            else
            {
                s2 += s[i];
            }
        }

        return s2 == t2;
    }
};
// @lc code=end

