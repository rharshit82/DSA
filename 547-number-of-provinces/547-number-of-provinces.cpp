class Solution {
public:
    int find(int x,vector<int>&parents){
        return parents[x]==x? x: find(parents[x],parents);
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<int> parents(n);
        for(int i=0; i<n; i++) parents[i]=i;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr[0].size(); j++){
                if(arr[i][j]==1){
                    int x = find(i,parents);
                    int y = find(j,parents);
                    if(x!=y){
                        parents[x]=y;
                    }
                }
            }
        }
        int res=0;
        for(int i=0; i<n; i++){
            if(parents[i]!=i) res++;
        }
        return n-res;
    }
};