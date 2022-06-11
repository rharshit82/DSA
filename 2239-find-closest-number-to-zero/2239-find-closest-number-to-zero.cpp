class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;
        for(int i=0,j=0; i<(int)1e6 and j>(int)-1e6; i++, j--){
            if(mp.find(i)!=mp.end()) return i;
            if(mp.find(j)!=mp.end()) return j;
        }
        return 0;
    }
};