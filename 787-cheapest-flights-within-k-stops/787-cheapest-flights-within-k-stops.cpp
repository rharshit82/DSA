class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        dist[src]=0;
        for(int i=0; i<=k; i++){
            vector<int> temp(dist);
            for(auto flight: flights){
                int from = flight[0];
                int to = flight[1];
                int weight = flight[2];
                temp[to] = min(temp[to],dist[from]+weight);
            }
            dist = temp;
        }
        return dist[dst] == 1e9? -1: dist[dst];
    }
};