class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt=0;
        int n=rating.size();
        int ls,lb,rs,rb;
        for(int i=1;i<n-1;i++)
        {
            ls=0;
            rs=0;
            lb=0;
            rb=0;
            for(int j=0;j<i;j++)
            {
                if(rating[i]<rating[j])
                {
                    lb+=1;
                }
                else if(rating[i]>rating[j])
                {
                    ls+=1;
                }
            }
            for(int j=i+1;j<n;j++)
            {
                if(rating[i]<rating[j])
                {
                    rb+=1;
                }
                else if(rating[i]>rating[j])
                {
                    rs+=1;
                }
            }
            cnt+=ls*rb + rs*lb;
        }
        return cnt;
    }
};