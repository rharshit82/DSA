class Solution {
public:
    
    //prefix[j] - prefix[i-1]= target
    //prefix[i-1] = prefix[j] - target
    // We will find Number of prefix[i-1] in our Map
    //Current sum will be prefix[j];
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        map<int,int> mp;
        int sum=0;
        int numSubArrays=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(sum==goal) numSubArrays++;
            numSubArrays+=mp[sum-goal];
            mp[sum]++;
        }
        return numSubArrays;
    }
};