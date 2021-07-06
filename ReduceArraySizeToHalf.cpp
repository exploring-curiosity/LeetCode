class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> hash;
        vector<int> freq;
        int res=0,cur,n=arr.size();
        cur=n;
        for(int i:arr)hash[i]++;
        for(auto i:hash) freq.emplace_back(i.second);
        sort(freq.begin(),freq.end(),greater<int>());
        for(int i:freq)
        {
            cur-=i;
            res++;
            if(cur<=n/2) break;
        }
        return res;
    }
};