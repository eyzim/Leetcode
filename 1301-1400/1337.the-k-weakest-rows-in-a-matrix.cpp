/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class SolutionBrute&Multimap {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        // store the weakest k value
        multimap<int, int> mp;

        // traverse all of the rows 
        for(auto i=0; i<mat.size(); i++) {
            
            int soldiers = 0;
            
            for(auto j=0; j<mat[0].size(); j++) {
                if(mat[i][j]) soldiers++;
            }

            mp.insert(make_pair(soldiers, i));
        }

        vector<int> ans;

        auto it = mp.begin();
        for(auto i=0; i<k && it != mp.end(); i++, it++)
        {
            ans.push_back(it->second);
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pair<int, int>> pq;

        int l = mat[0].size()-1;

        // go through with the count of the row
        for(auto i=0; i<mat.size(); i++) {
            int start = 0, end = l, soldiers = 0; 
            while(start <= end) {
                int mid = (start+end)>>1;
                if(mat[i][mid]) {
                    soldiers = mid+1;
                    start = mid+1;
                }
                else {
                    end = mid-1;
                }
            }

            pq.push({soldiers, i});

            // clean up the overflow elements
            if(pq.size()>k) {
                pq.pop();
            }
        }

        // pop out the k smallest element
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end
