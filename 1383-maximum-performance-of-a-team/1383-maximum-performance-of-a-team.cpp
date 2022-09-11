class Solution {
public:
    int MOD = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> candidates(n);
        for(int i=0; i<n; i++){
            candidates[i] = {efficiency[i], speed[i]};
        }
        sort(candidates.rbegin(), candidates.rend());
        long long res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long speedSum = 0;
        for(auto& [e, s]: candidates){
            speedSum+=s;
            pq.push(s);
            if(pq.size()>k){
                speedSum-=pq.top();
                pq.pop();
            }
            res = max(res, 1LL* e * speedSum);
        }
        return res%MOD;
    }
};