class Solution {
public:
    vector<string> res;
    void traverse(string s,int available,int opened,int n)
    {
        if(s.size()==n*2)
        {
            res.push_back(s);
            return;
        }
        if(opened<n)
        {
            traverse(s+"(",available+1,opened+1,n);
        }
        if(available>0)
        {
            traverse(s+")",available-1,opened,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        traverse("(",1,1,n);
        return res;
    }
};