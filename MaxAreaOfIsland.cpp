class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(int i,int j,vector<vector<int>>& grid,int area)
    {
        int maxArea=area;
        grid[i][j]=2;
        for(int k=0;k<dir.size();k++)
        {
            int x=i+dir[k][0];
            int y=j+dir[k][1];
            if(x<grid.size()&&y<grid[0].size()&&grid[x][y]==1)
                maxArea=max(maxArea,dfs(x,y,grid,maxArea))+1;
        }
        return maxArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    res=max(res,dfs(i,j,grid,1));
                }
            }
        }
        return res;
    }
};