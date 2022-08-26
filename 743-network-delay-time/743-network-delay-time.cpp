class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        for(int i=0; i<times.size(); i++){
            g[times[i][0]].push_back({times[i][1], times[i][2]});
        }
         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> vis(n+1, false);
        vector<int> dis(n+1, INT_MAX);
        
        pq.push({0, k});
        dis[k] = 0;
        
        while(!pq.empty()){
            int curr = pq.top().second;
            int currdis = pq.top().first;
            pq.pop();
            if(vis[curr]) continue;
            vis[curr] = true;
            for(auto e: g[curr]){
                int node = e.first;
                int nodedis = e.second;
                if(vis[node]) continue;
                
                if(currdis+nodedis < dis[node]){
                    dis[node] = currdis+nodedis;
                    pq.push({dis[node], node});
                }
            }
        }
        int res = 0;
        for(int i=1; i<=n; i++){
            res = max(res, dis[i]);
        }
        return res == INT_MAX? -1: res;
    }
};