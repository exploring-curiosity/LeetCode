class Solution {
public:
    int minCoststair(vector<int>& cost,vector<int>& stairCostMem,int i)
    {
        if(i>=cost.size())
            return 0;
        int f1=0,f2=0;
        if((i+1)<cost.size())
        {
            if(stairCostMem[i+1]!=-1)
            {
                f1=stairCostMem[i+1];
            }
            else
            {
                f1=minCoststair(cost,stairCostMem,i+1);
                stairCostMem[i+1]=f1;
            }
        }
        if((i+2)<cost.size())
        {  
            if(stairCostMem[i+2]!=-1)
            {
                f2=stairCostMem[i+2];
            }
            else
            {
                f2=minCoststair(cost,stairCostMem,i+2);
                stairCostMem[i+2]=f2;
            } 
        }
        return cost[i]+min(f1,f2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int res=0;
        vector<int> stairCostMem(cost.size(),-1);
        return min(minCoststair(cost,stairCostMem,0),minCoststair(cost,stairCostMem,1));
    }
};