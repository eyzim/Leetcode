/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;

        for(auto i:s) {
            mp[i]++;
        }

        for(auto i=0; i<s.size(); i++) {
            if(mp[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end

