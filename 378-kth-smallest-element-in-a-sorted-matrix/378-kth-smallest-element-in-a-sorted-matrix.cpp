class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        for(int i=0;i<min(n,k); i++){
            pq.push({matrix[i][0],i,0});
        }
        int ans;
        for (int i = 1; i <= k; ++i) {
            auto top = pq.top(); pq.pop();
            int r = top[1], c = top[2];
            ans = top[0];
            if (c + 1 < n) pq.push({matrix[r][c + 1], r, c + 1});
        }
        return ans;
    }
};