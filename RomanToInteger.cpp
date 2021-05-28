class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        int val=0;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        m['~']=10000;
        char prev='~';
        for(int i=0;i<s.size();i++)
        {
            if(m[prev]>=m[s[i]])
            {
                val+=m[s[i]];
            }
            else
            {
                val=val-2*m[prev]+m[s[i]];
            }
            prev=s[i];
        }
        return val;
    }
};