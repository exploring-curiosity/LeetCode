class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int pt1=0,left,right;
        int closest=100000;
        int n=nums.size();
        while(pt1<(n-2))
        {
            left=pt1+1;
            right=n-1;
            while(left<right)
            {
                int sum=(nums[pt1]+nums[left]+nums[right]);
                if(abs(sum-target)<abs(closest-target))
                {
                    closest=sum;
                    if(closest==target)
                        return target;
                }
                else
                {
                    if(sum-target<0)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
            pt1++;
        }  
        return closest;
    }
};