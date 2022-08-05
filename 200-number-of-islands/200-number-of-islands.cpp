class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dir[] = {-1,0,1,0,-1};
        int numOfIslands=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!='1') continue;
                queue<pair<int,int>> q;
                q.push({i,j});
                grid[i][j]=2;
                while(!q.empty()){
                    int r= q.front().first;
                    int c= q.front().second;
                    q.pop();
                    for(int i=0; i<4; i++){
                        int nr = r + dir[i];
                        int nc = c + dir[i+1];
                        if(nr<0 or nc<0 or nr>=n or nc>=m or grid[nr][nc]!='1') continue;
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
                numOfIslands++;
            }
        }
        return numOfIslands;
    }
};