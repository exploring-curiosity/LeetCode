class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int pt1=0,pt2,pt3,pt4;
        long sum=0;
        vector<vector<int>> res;
        int n=nums.size();
        if(n<4)
            return res;
        sort(nums.begin(),nums.end());
        while(pt1<n-3)
        {
            pt2=pt1+1;
            while(pt2<n-2)
            {
                pt3=pt2+1;
                pt4=n-1;
                while(pt3<pt4)
                {
                    sum= nums[pt1]+nums[pt2]+nums[pt3]+nums[pt4];
                    if(sum==target)
                    {
                        res.push_back({nums[pt1],nums[pt2],nums[pt3],nums[pt4]});
                        int last_left=nums[pt3];
                        int last_right=nums[pt4];
                        do{
                            pt3++;
                        }while(pt3<pt4 && nums[pt3]==last_left);
                        do{
                            pt4--;
                        }while(pt3<pt4 && nums[pt4]==last_right);
                    }
                    else
                    {
                        if(sum<target)
                        {
                            int last_left=nums[pt3];
                            do{
                                pt3++;
                            }while(pt3<pt4 && nums[pt3]==last_left);
                        }
                        else
                        {
                            int last_right=nums[pt4];
                            do{
                                pt4--;
                            }while(pt3<pt4 && nums[pt4]==last_right);
                        }
                    }
                }
                int last_pt2=nums[pt2];
                do{
                    pt2++;
                }while(pt2<(n-2)&& nums[pt2]==last_pt2);
            }
            int last_pt1=nums[pt1];
            do{
                pt1++;
            }while(pt1<(n-3) && nums[pt1]==last_pt1);
        }
        return res;
    }
};