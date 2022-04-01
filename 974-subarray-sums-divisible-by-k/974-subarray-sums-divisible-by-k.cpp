class Solution {
public:
    //remainder is x now. We added enough values that remainder is x again. 
    //This means sum of elements between is multiple of k
    //freq[0]=1 in order for my counter to consider the first subarray with a remainder that equals to zero
    // For negative numbers, if rem = -5, it wont be divisible by k=5. We add k to negative remainders.
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0;
        int res=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            int rem = sum%k;
            if(rem<0) rem+=k;
            res+=mp[rem];
            mp[rem]++;
        }
        return res;
    }
};