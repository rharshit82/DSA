class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n;i++){
            mp[nums[i]]++;
        }
        int res=0;
        for(auto ele: mp){
            if(k==0){
                if(ele.second>1) res++;
            }
            else if(mp.find(ele.first+k)!=mp.end()) res++;
        }
        return res;
    }
};