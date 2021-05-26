class Solution {
public:
    int myAtoi(string s) {
        bool neg=false;
        bool aws=true,asign=true,max=false;
        long num=0;
        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
            {
                if(num>INT_MAX)
                    break;
                aws=false;
                asign=false;
                num*=10;
                num+=s[i]-'0';
            }
            else if(s[i]==' ' && aws)
                continue;
            else if((s[i]=='+' || s[i]=='-')&&asign)
            {
                asign=false;
                aws=false;
                if(s[i]=='-')
                    neg=true;
            }
            else
                break;
        }
        if(neg)
        {
            num=-1*num;
            if(num<INT_MIN)
                return INT_MIN;
            return int(num);
        }
        if(num>INT_MAX)
            return INT_MAX;
        return int(num);
    }
};