class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if(numRows==1)
            return s;
        int ext=2*numRows-2;
        for(int i=0;i<numRows;i++)
        {
            for(int j=i;j<s.size();j+=ext)
            {
                int k=j+ext-i*2;
                res.push_back(s[j]);
                if(k!=j&&k!=(j+ext)&&k<s.size())
                    res.push_back(s[k]);
            }
        }
        return res;
    }
};