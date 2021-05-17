class Solution {
public:
    vector<int> treelen;
    map<int,vector<string>> m;
    map<string,int> rNode;
    bool isPword(string word1,string word2)
    {
        if(word1.size()!=word2.size()-1)
            return false;
        int s;
        bool flag=false;
        for(auto i:word1)
        {
            if(i==word2[0])
            {
                word2.erase(word2.begin()+0);
            }
            else if(i==word2[1])
            {
                if(flag)
                    return false;
                flag=true;
                word2.erase(word2.begin()+0);
                word2.erase(word2.begin()+0);
            }
            else
                return false;
        }
        return true;
    }
    int traverse(string root)
    {
        int level=root.length()+1;
        auto itr = m.find(level);
        if(itr==m.end())
        {
            rNode[root]=1;
            return 1;
        }
        int flag=0;

        for(auto i:itr->second)
        {
            if(isPword(root,i))
            {
                if(rNode[i]==0)
                {    
                    rNode[i] = traverse(i);
                }
                if(rNode[root]<rNode[i]+1)
                {
                    rNode[root]=rNode[i]+1;
                }
                flag=1;
            }
        }
        if(flag==0)
        {
            rNode[root]=1;
            return 1;
        }
        return rNode[root];
    }
    int longestStrChain(vector<string>& words) {
        for(auto itr:words)
        {
            m[itr.length()].push_back(itr);
            rNode[itr] = 0;
        }
        for(auto itr:words)
        {
            if(rNode[itr]==0)
            treelen.push_back(traverse(itr));
        }
        
        return *max_element(treelen.begin(),treelen.end());
    }
};