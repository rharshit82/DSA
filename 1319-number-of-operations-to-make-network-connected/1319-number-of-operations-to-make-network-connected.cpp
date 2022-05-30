class Solution {
public:
    int find(int x){
        return parent[x]==x? x: find(parent[x]);
    }
    vector<int> parent;
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size()) return -1;
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i]=i;
        
        for(int i=0; i<connections.size(); i++){
            int a=connections[i][0];
            int b=connections[i][1];
            int x=find(a);
            int y=find(b);
            if(x!=y){
                parent[x]=y;
            }
        }
        int conn=0;
        for(int i=0; i<n; i++){
            if(parent[i]==i) conn++;
        }
        return conn-1;
    }
};