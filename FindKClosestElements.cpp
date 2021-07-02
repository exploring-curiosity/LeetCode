class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0,r=k;
        while(r<arr.size())
        {
            if(abs(arr[l]-x)<abs(arr[r]-x))break;
            else if(abs(arr[l]-x)==abs(arr[r]-x) && arr[l]<arr[r]) break;
            r++;
            l++;
        }
        vector<int> res;
        while(l<r)res.push_back(arr[l++]);
        return res;
    }
};