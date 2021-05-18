class Solution {
public:
    void tokenize(string const &str,vector<string> &out) 
    { 
        char *token = strtok(const_cast<char*>(str.c_str()), " "); 
        while (token != nullptr) 
        { 
            out.push_back(string(token)); 
            token = strtok(nullptr, " "); 
        }
    }
    void content(string const &str,pair<string,string> &fc)
    {
        char *token = strtok(const_cast<char*>(str.c_str()), "("); 
        int flag=true;
        while (token != nullptr)
        {
            if(flag)
            {
                fc.first = string(token);
                flag=false;
            }
            else
                fc.second = string(token);
            token = strtok(nullptr, "("); 
        }
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        vector<string> tokens;
        unordered_map<string,vector<string>> m;
        pair<string,string> fc;
        for(auto itr:paths)
        {
            tokenize(itr,tokens);
            for(int i=1;i<tokens.size();i++)
            {
                content(tokens[i],fc);
                m[fc.second].push_back(tokens[0]+"/"+fc.first);
            }
            tokens.clear();
        }
        for(auto itr:m)
        {
            if(itr.second.size()>1)
            res.push_back(itr.second);
        }
        return res;
    }
};