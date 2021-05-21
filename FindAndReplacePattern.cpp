class Solution {
public:
    bool isMatch(string word,string pattern)
    {
        unordered_map<char,char> m;
        vector<char> matched;
        for(auto itr:word)
            m[itr]='0';
        
        for(int i=0;i<word.size();i++)
        {
            if(m[word[i]]=='0')
            {
                if(find(matched.begin(),matched.end(),pattern[i])==matched.end())
                {
                    m[word[i]]=pattern[i];
                    matched.push_back(pattern[i]);
                }
                else
                    return false;
            }
            else
            {
                if(m[word[i]]!=pattern[i])
                    return false;
            }
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto itr:words)
        {
            if(isMatch(itr,pattern))
                res.push_back(itr);
        }
        return res;
    }
};