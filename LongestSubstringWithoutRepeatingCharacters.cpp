class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx=0;
        vector<bool> loc(256,false);
        queue<int> q;
        for(int i=0;i<s.size();i++)
        {
            if(!loc[s[i]])
            {
                loc[s[i]]=true;
                q.push(s[i]);
            }
            else
            {
                if(mx<q.size())
                {
                    mx=q.size();
                }
                while(q.front()!=s[i])
                {
                    loc[q.front()]=false;
                    q.pop();
                }
                q.pop();
                q.push(s[i]);
            }
        }
        if(mx<q.size())
        {
            mx=q.size();
        }
        return mx;
    }
};