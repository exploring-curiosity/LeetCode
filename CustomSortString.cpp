class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> freq(26,0);
        for(char ch:str) freq[ch-'a']++;
        string res="";
        for(char c:order)
        {
            while(freq[c-'a']>0) res+=c,freq[c-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            while(freq[i]>0) res+=('a'+i),freq[i]--;
        }
        return res;
    }
};