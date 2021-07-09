class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i:nums)
        {
            if(dp.back()<i) dp.push_back(i);
            else *lower_bound(dp.begin(),dp.end(),i)=i;
        }
        return dp.size();
    }
};