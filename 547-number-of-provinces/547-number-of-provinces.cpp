class Solution {
public:
    vector<int> parent;
    int find(int x){
        return parent[x]==x?x: find(parent[x]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        if(!n) return 0;
        parent.resize(n,0);
        int res=n;
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]){
                int x=find(i);
                int y=find(j);
                if(x!=y){
                    parent[x]=y;
                    res--;
                }
                }
            }
        }
        return res;
    }
};