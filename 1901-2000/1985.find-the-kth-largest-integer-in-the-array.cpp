/*
 * @lc app=leetcode id=1985 lang=cpp
 *
 * [1985] Find the Kth Largest Integer in the Array
 */

// @lc code=start
class compar{       
public: 
    bool operator()(string &a, string &b)
    {
        if(a.size() == b.size())
        {
            return a > b;
        }
        return a.size() > b.size();
    };
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        // using the customized comparator
        priority_queue<string, vector<string>, compar> pq;

        for(auto i:nums)
        {
            pq.push(i);

            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        return pq.top();
    }
};
// @lc code=end

