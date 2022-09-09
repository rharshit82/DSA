class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        int n= arr.size();
        vector<int> pref(n, 0);
        pref[0] = arr[0];
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1]^arr[i];
        }
        for(auto &x: queries){
            int r = pref[x[1]];
                r^=pref[x[0]];
                r^=arr[x[0]];
            res.push_back(r);
        }
        return res;
    }
};