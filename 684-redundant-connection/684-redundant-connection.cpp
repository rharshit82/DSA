class Solution {
public:
    vector<int> parents;
    int find(int x){
        return x==parents[x]? x: find(parents[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parents.resize(n+1,0);
        for(int i=0;i<=n;i++)
            parents[i]=i;
        
        vector<int> res(2,0);
        for(int i=0;i<n;i++){
            int x=find(edges[i][0]);
            int y=find(edges[i][1]);
            if(x!=y){
                parents[y]=x;
            }
            else{
                res[0]=edges[i][0];
                res[1]=edges[i][1];
            }
        }
        return res;
        
    }
};