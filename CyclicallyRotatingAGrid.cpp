class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int l=0,i=0;
        vector<int> layer;
        
        while(m>0 && n>0)
        {
            layer.clear();
            for(i=l;i<m+l;i++)
                layer.push_back(grid[l][i]);
            for(i=l+1;i<n+l;i++)
                layer.push_back(grid[i][m+l-1]);
            for(i=m+l-2;i>=l;i--)
                layer.push_back(grid[n+l-1][i]);
            for(i=n+l-2;i>l;i--)
                layer.push_back(grid[i][l]);
            int s=layer.size();
            layer.insert(layer.end(),layer.begin(),layer.begin()+k%s);
            int j=k%s;
            for(i=l;i<m+l;i++)
                grid[l][i]=layer[j++];
            for(i=l+1;i<n+l;i++)
                grid[i][m+l-1]=layer[j++];
            for(i=m+l-2;i>=l;i--)
                grid[n+l-1][i]=layer[j++];
            for(i=n+l-2;i>l;i--)
                grid[i][l]=layer[j++];
            m-=2;
            n-=2;
            l+=1;
        }
        
        return grid;
    }
};