class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        
        int dir[]={0,1,0,-1,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        int res=0;
        while(!q.empty()){
            if(q.size() == n*m)
            return -1;
            int size=q.size();
            res++;
            while(size--){
                auto [r,c]=q.front(); q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+dir[i];
                    int nc=c+dir[i+1];
                    if(nr<0 or nc<0 or nr>=m or nc>=n or grid[nr][nc]!=0) continue;
                    q.push({nr,nc});
                    grid[nr][nc]=1;
                }
            }
        }
        return res-1;
    }
};