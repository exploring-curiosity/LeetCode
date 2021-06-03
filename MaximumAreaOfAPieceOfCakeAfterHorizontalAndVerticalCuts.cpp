class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxHcut=0,maxVcut=0;
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        for(int i=0;i<horizontalCuts.size()-1;i++)
        {
            maxHcut=max(maxHcut,horizontalCuts[i+1]-horizontalCuts[i]);      
        }
        for(int i=0;i<verticalCuts.size()-1;i++)
        {
            maxVcut=max(maxVcut,verticalCuts[i+1]-verticalCuts[i]);      
        }
        return (long(maxHcut)*maxVcut)%1000000007;
    }
};