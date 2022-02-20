class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n=grid.size();
        vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
        int res=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            auto [r,c]=q.front(); q.pop();
            if(r==n-1 and c==n-1) return grid[r][c];
            for(auto i: dir){
                int nr=r+i[0];
                int nc=c+i[1];
                if(nr<0 or nc<0 or nr>=n or nc>=n or grid[nr][nc]!=0) continue;
                q.push({nr,nc});
                grid[nr][nc]=grid[r][c]+1;
            }
        }
        return -1;
    }
};