class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> mp;
        int n=time.size();
        int res=0;
        for(int i=0; i<n; i++){
            res+= mp[(60- (time[i]%60))%60];
            mp[time[i]%60]++;
        }
        return res;
    }
};