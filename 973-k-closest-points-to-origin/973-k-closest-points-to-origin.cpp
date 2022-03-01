class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            int dis=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({dis,{points[i][0],points[i][1]}});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> res(k,vector<int>(2));
        for(int i=0;i<k;i++){
            res[i][0]=pq.top().second.first;
            res[i][1]=pq.top().second.second;
            pq.pop();
        }
        return res;
        
        
    }
};