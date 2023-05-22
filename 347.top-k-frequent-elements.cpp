/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        // count all frequecies
        unordered_map<int, int> mp;        
        for(auto i:nums)
        {
            mp[i]++;
        }

        // sort by frequencies
        priority_queue<pair<int, int>> pq;
        for(auto i:mp)
        {
            pq.push(make_pair(i.second, i.first));
        }

        // get the top k frequecies
        vector<int> ans;
        for(int i=0; i<k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();            
        }

        return ans;
    }
};
// @lc code=end

