class Solution {
public:
    bool isopr(string s)
    {
        if(s.size()>1)
            return false;
        if(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/')
            return true;
        return false;
    }
    int compute(int a,int b,char opr)
    {
        if(opr=='+')
            return a+b;
        if(opr=='-')
            return a-b;
        if(opr=='*')
            return a*b;
        float op=a*1.0/b;
        if(op>=0)
            return floor(op);
        else 
            return ceil(op);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int op1,op2;
        for(auto itr:tokens)
        {
            if(isopr(itr))
            {
                op2=stk.top();
                stk.pop();
                op1=stk.top();
                stk.pop();
                stk.push(compute(op1,op2,itr[0]));
            }
            else
            {
                stk.push(stoi(itr));
            }
        }
        return stk.top();
    }
};