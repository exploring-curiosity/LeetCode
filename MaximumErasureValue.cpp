class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int max=nums[0],sum=nums[0];
        unordered_set<int> repeated;
        repeated.insert(nums[0]);
        int left=0,right=1;
        while(right<nums.size())
        {
            if(repeated.find(nums[right])==repeated.end())
            {
                repeated.insert(nums[right]);
                sum+=nums[right];
                right++;
            }
            else
            {
                if(max<sum)
                {
                    max=sum;
                }
                while(nums[left]!=nums[right])
                {
                    sum=sum-nums[left];
                    repeated.erase(nums[left]);
                    left++; 
                }
                left++;
                right++;
            }
        }
        if(max<sum)
        {
            max=sum;
        }
        return max;
    }
};