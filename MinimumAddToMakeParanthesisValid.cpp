class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> stk;
        int cnt = 0;
        for(auto itr:s)
        {
            if(itr=='(')
                stk.push(itr);
            else
            {
                if(stk.size()==0)
                    cnt+=1;
                else
                    stk.pop();
            }
        }
        return cnt+stk.size();
    }
};