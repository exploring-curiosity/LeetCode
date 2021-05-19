class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int temp=nums[nums.size()/2];
        unsigned long long int cnt=0;
        for(auto it:nums)
        {
            cnt+=abs(temp-it);
        }
        return cnt;
    }
};