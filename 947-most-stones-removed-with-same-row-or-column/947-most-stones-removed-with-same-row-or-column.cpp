class Solution {
public:
    vector<int> parents;
    int find(int x){
        return x==parents[x]?x: find(parents[x]);
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parents.resize(n+1,0);
        for(int i=0;i<=n;i++) parents[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]){
                    int x=find(i);
                    int y=find(j);
                    if(x!=y) parents[y]=x;
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(parents[i]==i){
                res++;
            }
        }
        return n-res;
    }
};