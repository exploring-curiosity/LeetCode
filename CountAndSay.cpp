class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s=countAndSay(n-1),res="";
        int i,c=1;
        for(i=1;i<s.size();i++)
        {
            if(s[i-1]==s[i])
                c++;
            else
            {
                res+=to_string(c);
                res+=s[i-1];
                c=1;
            }
        }
        res+=to_string(c);
        res+=s[i-1];
        return res;
    }
};