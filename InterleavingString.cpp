class Solution {
public:
    
    bool traverse(string s1, string s2, string s3,int itr1,int itr2,int itr3,vector<vector<int>> &dp)
    {
        int l1=s1.size(),l2=s2.size(),l3=s3.size();
        for(int i=itr3;i<l3;i++)
        {
            if(itr1<l1 && s3[i]==s1[itr1])
            {
                if(itr2<l2 && s3[i]==s2[itr2])
                {
                    if(dp[itr1][itr2]!=-1)
                        return dp[itr1][itr2];
                    bool t1=traverse(s1,s2,s3,itr1+1,itr2,i+1,dp);
                    dp[itr1][itr2]=t1;
                    if(t1)
                        return t1;
                    bool t2=traverse(s1,s2,s3,itr1,itr2+1,i+1,dp);
                    dp[itr1][itr2]=t2;
                    return t2;
                }
                itr1++;
            }
            else if(itr2<l2 && s3[i]==s2[itr2])
            {
                itr2++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.size(),l2=s2.size(),l3=s3.size();
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        if(l3!=(l1+l2))
            return false;
        return traverse(s1,s2,s3,0,0,0,dp);
    }
};