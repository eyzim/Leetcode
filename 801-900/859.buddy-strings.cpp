/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if(s.length() != goal.length()) return 0;

        bool duplicate_alph = 0;

        unordered_map<char, int> mp;
        for(auto i:s) {
            mp[i]++;
        }
        // check duplicated alphabet
        if(mp.size() < s.size()) {
            duplicate_alph = 1;
        }
        // check two strings
        for(auto i:goal) {
            if(!mp[i])      return 0;
            if(mp[i] == 1)  mp.erase(i);
            else            mp[i]--;
        }
        if(mp.size() > 0)   return 0;

        // check different index one by one
        int count = 0;
        for(auto i=0; i<s.size(); i++) {
            if(s[i] != goal[i])     count++;
        }

        if(count==2)    return 1;
        // special case for 'aab'
        if(duplicate_alph==1 && count==0)   return 1;

        return 0;
    }
};
// @lc code=end

