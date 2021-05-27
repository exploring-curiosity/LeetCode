class Solution {
public:
    int maxProduct(vector<string>& words) {
        int mx=0;
        set<char> exists;
        bool flag;
        set<char>::iterator itr;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int k=0;k<words[i].size();k++)
            {
                exists.insert(words[i][k]);
            }
            for(int j=i+1;j<words.size();j++)
            {
                flag=true;
                for(int k=0;k<words[j].size();k++)
                {
                    itr=exists.find(words[j][k]);
                    if(itr!=exists.end())
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    int len=words[i].size()*words[j].size();
                    if(mx<len)
                        mx=len;
                }
            }
            exists.clear();
        }
        return mx;
    }
};