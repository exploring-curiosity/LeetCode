class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        stack<char> stk;
        int i;
        string s=to_string(x);
        for(i=0;i<s.size()/2;i++)
            stk.push(s[i]);
        if(s.size()%2!=0)
            i+=1;
        while(i<s.size())
        {
            if(s[i]!=stk.top())
                return false;
            stk.pop();
            i++;
        }
        return true;
    }
};