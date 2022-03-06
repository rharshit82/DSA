class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        map<long long,long long> mp;
        for(auto i: nums) mp[i]++;
        long long res=0;
        long long start=1;
        for(auto it: mp){
            long long l=start;
            long long r=it.first;
            if(k>r-l){
                k-=r-l;
            } else{
                break;
            }
            res+=(r*(r-1))/2 - (l*(l-1))/2;
            start=r+1;
        }
        // long long l=start;
        // long long r=start+k;
        res+=((start+k)*(start+k-1))/2-(start*(start-1))/2;
        return res;
    }
};