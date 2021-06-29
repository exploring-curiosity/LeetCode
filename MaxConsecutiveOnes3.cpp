class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int fz=0;
        int m=0;
        while(r<nums.size())
        {
            if(nums[r]==1)
                r++;
            else if(fz<k)
            {
                fz++;
                r++;
            }    
            else
            {
                
                m=max(m,r-l);
                if(nums[l]==0)
                {
                    fz--;
                    l++;
                }
                else
                    while(nums[l])l++;
            }
        }
        return max(m,r-l);
    }
};