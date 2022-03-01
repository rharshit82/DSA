class Solution {
public:
    typedef pair<int,pair<int,int>> ppi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<ppi> pq;
        for(auto ele: points){
            pq.push({ele[0]*ele[0]+ele[1]*ele[1],{ele[0],ele[1]}});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            res.push_back(temp);
            pq.pop();
        }
        return res;
    }
};