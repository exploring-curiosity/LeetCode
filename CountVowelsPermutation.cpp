class Solution {
public:
    int recurse(int n,char st,vector<vector<int>> &dp)
    {   
        int mod=1e9+7;
        if(n==0) return 1;
        long long res=0;
        if(st=='a')
        {
            if(dp[n][0]) return dp[n][0];
            res+=recurse(n-1,'e',dp);
            dp[n][0]=res%mod;
            return dp[n][0];
        }
        if(st=='e')
        {
            if(dp[n][1]) return dp[n][1];
            res+=recurse(n-1,'a',dp);
            res+=recurse(n-1,'i',dp);
            dp[n][1]=res%mod;
            return dp[n][1];
        }
        if(st=='i')
        {
            if(dp[n][2]) return dp[n][2];
            res+=recurse(n-1,'a',dp);
            res+=recurse(n-1,'e',dp);
            res+=recurse(n-1,'o',dp);
            res+=recurse(n-1,'u',dp);
            dp[n][2]=res%mod;
            return dp[n][2];
        }
        if(st=='o')
        {
            if(dp[n][3]) return dp[n][3];
            res+=recurse(n-1,'i',dp);
            res+=recurse(n-1,'u',dp);
            dp[n][3]=res%mod;
            return dp[n][3];
        }
        if(st=='u')
        {
            if(dp[n][4]) return dp[n][4];
            res+=recurse(n-1,'a',dp);
            dp[n][4]=res%mod;
            return dp[n][4];
        }
        return 0;
    }
    int countVowelPermutation(int n) {
        long long res=0,mod=1e9+7;
        vector<vector<int>> dp(n,vector<int>(5));
        res+=recurse(n-1,'a',dp);
        res+=recurse(n-1,'e',dp);
        res+=recurse(n-1,'i',dp);
        res+=recurse(n-1,'o',dp);
        res+=recurse(n-1,'u',dp);
        return res%mod;
    }
};