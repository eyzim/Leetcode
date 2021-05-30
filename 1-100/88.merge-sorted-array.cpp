/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m-1, q = n-1, t = m+n-1;

        while(p>=0 && q>=0)
        {
            if(nums1[p] > nums2[q])
            {
                nums1[t] = nums1[p];
                t--;
                p--;
            }
            else
            {
                nums1[t] = nums2[q];
                t--;
                q--;
            }        
        }

        while(q>=0)
        {
            nums1[t] = nums2[q];
            q--;
            t--;
        }
    }
};
// @lc code=end
