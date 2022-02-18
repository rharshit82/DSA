class Solution {
public:
    vector<int> parents;
    int find(int x){
        return parents[x]==x? x: find(parents[x]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size()) return -1;
        parents.resize(n,0);
        for(int i=0;i<n;i++)
            parents[i]=i;
        for(int i=0;i<connections.size();i++){
            int x=find(connections[i][0]);
            int y=find(connections[i][1]);
            if(x!=y){
                parents[y]=x;
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(parents[i]==i){
                res++;
            }
        }
        return res-1;
    }
};