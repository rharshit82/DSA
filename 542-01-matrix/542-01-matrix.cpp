class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int Dir[]={0,1,0,-1,0};
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)
                    q.push({i,j});
                else
                    mat[i][j]=-1;
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+Dir[i];
                int nc=c+Dir[i+1];
                if(nr<0 or nr>=m or nc<0 or nc>=n or mat[nr][nc]!=-1) continue;
                mat[nr][nc]=1+mat[r][c];
                q.push({nr,nc});
            }
        }
        return mat;
    }
};