/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverseWord(s, start, i - 1);
                start = i + 1;
            }
        }
        
        // Reverse the last word if it exists
        reverseWord(s, start, s.size() - 1);

        return s;
    }

private:
    void reverseWord(string& s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }
};

// @lc code=end

