class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        if(n1+n2!=n3) return false;
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n1+1, vector<bool>(n2+1,false));
        q.push({0,0});
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i==n1 and j==n2) return true;
            if(vis[i][j]) continue;
            if(i<n1 and s1[i]==s3[i+j]){
                q.push({i+1,j});
            }
            if(j<n2 and s2[j]==s3[i+j]){
                q.push({i,j+1});
            }
            vis[i][j]=true;
        }
        return false;
    }
};