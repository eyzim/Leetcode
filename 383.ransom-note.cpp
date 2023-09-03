/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        // if the source is too short to construct our note
        if(ransomNote.size() > magazine.size())
        {
            return false;
        }

        unordered_map<char, int> mp;
  
        // count the occurrences of each character in the magazine
        for(auto i:magazine) {
            mp[i]++;
        }

        // check if there are enough resources (characters) available in the magazine to construct the ransomNote
        for(auto i:ransomNote) {
            if(mp[i]) {
                mp[i]--;
            }
            else {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

// Space: O(n)
// Time: O(m+n)