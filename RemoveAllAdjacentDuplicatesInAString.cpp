class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        
        for(int i=0;i<s.size();i++)
        {
            if(!stk.empty() && stk.top()==s[i])
            {
                stk.pop();
            }
            else
                stk.push(s[i]);
        }
        string res;
        while(!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};