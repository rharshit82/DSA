class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        int sum=0;
        int n=nums.size();
        map<int,int> mp;
        mp[0]=1;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())
                res+=mp[sum-k];
            mp[sum]++;
        }
        return res;
    }
};