class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int max=nums[0],sum=nums[0];
        vector<bool> repeated(10000,false);
        repeated[nums[0]]=true;
        int left=0,right=1;
        while(right<nums.size())
        {
            if(repeated[nums[right]]==false)
            {
                repeated[nums[right]]=true;;
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
                    repeated[nums[left]]=false;
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