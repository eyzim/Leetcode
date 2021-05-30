/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        
        path += "/";
        string temp_str = "";
        vector<string> temp;

        for(auto i=0; i<path.size(); i++)
        {
            if(path[i] != '/')
            {
                temp_str += path[i];
            }
            // up a level for ".."
            else if(temp_str == "..")
            {
                if(temp.size())
                {
                    temp.pop_back();
                }
                temp_str = "";
            }
            else if(temp_str.size())
            {
                // ignore only .
                if(temp_str != ".")
                {
                    temp.push_back(temp_str);
                }
                temp_str = "";
            }
        }

        string ans = "";

        for(auto i: temp)
        {
            ans += '/';
            ans += i;
        }

        return ans.size() ? ans : "/";
    }
};
// @lc code=end

