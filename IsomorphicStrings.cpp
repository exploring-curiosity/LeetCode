class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> hash1(256,-1),hash2(256,-1);
        for(int i=0;i<s.size();i++)
        {
            if(hash1[s[i]]==-1 && hash2[t[i]]==-1)
            {
                hash1[s[i]]=t[i];
                hash2[t[i]]=s[i];
            }
            else if(hash1[s[i]]==t[i] && hash2[t[i]]==s[i]) continue;
            else return false;
        }
        return true;
    }
};