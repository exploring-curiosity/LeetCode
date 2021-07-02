class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)k++;
            else nums[i-k]=nums[i];
        }
        cout<<k;
        return nums.size()-k;
    }
};