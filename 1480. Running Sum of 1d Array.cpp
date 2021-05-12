class leetcode1480 {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(auto i=1; i<nums.size(); i++)
        {
            nums[i] += nums[i-1];
        }
        return nums;
    }
};