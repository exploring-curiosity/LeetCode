class Solution {
public:
    string intToRoman(int num) {
        string res;
        stack<int> val;
        int unit=0,digit;
        char u1,u5,u10;
        do
        {
            val.push(num%10);
            num/=10;
            unit++;
        }while(num!=0);
        while(!val.empty())
        {
            digit=val.top();
            val.pop();
            if(unit==1)
            {
                u1='I';
                u5='V';
                u10='X';
            }
            else if(unit==2)
            {
                u1='X';
                u5='L';
                u10='C';
            }
            else if(unit==3)
            {
                u1='C';
                u5='D';
                u10='M';
            }
            else
            {
                u1='M';
                u5='~';
                u10='~';
            }
            if(digit<4)
            {
                for(int i=0;i<digit;i++)
                {
                    res.push_back(u1);
                }
            }
            else if(digit==4)
            {
                res.push_back(u1);
                res.push_back(u5);
            }   
            else
            {
                if(digit==9)
                {
                    res.push_back(u1);
                    res.push_back(u10);
                }
                else
                {
                    res.push_back(u5);
                    for(int i=0;i<digit-5;i++)
                    {
                        res.push_back(u1);
                    }
                }
            }
            unit--;
        }
        return res;
    }
};