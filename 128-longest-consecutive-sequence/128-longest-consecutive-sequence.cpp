class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(auto ele: nums){
            mp[ele]++;
        }
        int res=0;
        int cur=1;
        for(auto ele: mp){
            if(mp.find(ele.first-1)!=mp.end()){
                cur++;
            } else{
                cur=1;
            }
            res = max(res, cur);
        }
        return res;
    }
};