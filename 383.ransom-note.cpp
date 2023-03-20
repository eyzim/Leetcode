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
  
        // count how much resources/chars from magazines we get
        for(auto i:magazine){
            mp[i]++;
        }

        // check one by one of ransomNote, if we have enough chars, keep going; 
        // if we are lacking of chars, return false.
        // if we finished ransomNote, return true.
        for(auto j:ransomNote)
        {
            if(mp[j])
            {
                mp[j]--;

            }
            else
            {
                return false;
            }
        }  

        return true;
    }
};
// @lc code=end
