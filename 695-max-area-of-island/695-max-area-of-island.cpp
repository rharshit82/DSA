class Solution {
public:
    int area(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i<0 or j<0 or i>=m or j>=n or grid[i][j]!=1) return 0;
        grid[i][j]=0;
        return 1+ area(grid,i+1,j,m,n)+ area(grid,i-1,j,m,n)+ area(grid,i,j+1,m,n)+ area(grid,i,j-1,m,n);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    res=max(res,area(grid,i,j,m,n));
            }
        }
        return res;
    }
};