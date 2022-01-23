class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(auto i: nums){
            mp[i]++;
        }
        for(auto i: nums){
            if(mp[i]==1 && mp[i+1]==0 && mp[i-1]==0)
                res.push_back(i);
        }
        return res;
    }
};