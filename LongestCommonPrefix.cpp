class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        char temp;
        int i=0;
        bool flag=false;
        while(true){
            if(i<strs[0].size())
                temp=strs[0][i];
            else
                break;
            for(auto itr:strs)
            {
                if(itr.size()<=i)
                {
                    flag=true;
                    break;
                }
                if(itr[i]!=temp)
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
            i++;
            prefix.push_back(temp);
        }
        return prefix;
    }
};