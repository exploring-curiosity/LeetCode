class Solution {
public:
    int supersize=300;
    string superstr;
    int overlapcounter(string word1,string word2)
    {
        int m=word1.size(),n=word2.size();
        int len=min(m,n);
        string s1,s2;
        for(int i=len-1;i>0;i--)
        {
            s1 = word1.substr(m-i,i);
            s2 = word2.substr(0,i);
            if(s1.compare(s2)==0)
            {
                return i;
            }
        }
        return 0;
    }
    void overlap(string &str,string word,int oc)
    {
        for(int i=oc;i<word.size();i++)
        {
            str.push_back(word[i]);
        }
    }
    void construct(vector<string> words,int index,string str)
    {
        string word1=words[index];
        words.erase(words.begin()+index);
        overlap(str,word1,overlapcounter(str,word1));
        if(words.size()==0)
        {
            if(str.size()<supersize)
            {
                superstr=str;
                supersize=str.size();
            }
            return;
        }
        int oc=-2,temp;
        vector<int> inds;
        for(int i=0;i<words.size();i++)
        {
            temp = overlapcounter(str,words[i]);
            if(oc<temp)
            {
                oc=temp;
                inds.clear();
                inds.push_back(i);
            }
            else if(oc==temp)
            {
                inds.push_back(i);
            }
        }
        for(auto itr:inds)
        {
            construct(words,itr,str);
        }
    }
    string shortestSuperstring(vector<string>& words) {  
        for(int i=0;i<words.size();i++)
        {
            construct(words,i,"");
        }
        return superstr;
    }
};