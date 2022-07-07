class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            while(nums[i]>0 and nums[i]<n and nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=1; i<=n; i++){
            if((nums[i-1]!=i)) return i;
        }
        return n+1;
    }
};