class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int pt1=0,left,right;
        vector<vector<int>> res;
        int n=nums.size();
        if(nums.size()<3)
            return res;
        while(pt1<(n-2))
        {
            left=pt1+1;
            right=n-1;
            if(nums[pt1]>0)
            {
                return res;
            }
            while(left<right)
            {
                int sum=(nums[pt1]+nums[left]+nums[right]);
                if(sum==0)
                {
                    res.push_back({nums[pt1],nums[left],nums[right]});
                    do{
                        left++;
                    }while(left<right && nums[left]==nums[left-1]);
                    do{
                        right--;
                    }while(left<right && nums[right]==nums[right+1]);
                }
                else
                {
                    if(sum<0)
                    {
                        do{
                            left++;
                        }while(left<right && nums[left]==nums[left-1]);
                    }
                    else
                    {
                        do{
                            right--;
                        }while(left<right && nums[right]==nums[right+1]);
                    }
                }
            }
            do{
                pt1++;
            }while(pt1<(n-2) && nums[pt1]==nums[pt1-1]);
        }  
        return res;
    }
};