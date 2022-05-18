class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int mx1=INT_MIN;
        int mx2=INT_MIN;
        int mx3=INT_MIN;
        int mn1=INT_MAX;
        int mn2=INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i]>=mx1){
                mx3=mx2;
                mx2=mx1;
                mx1=nums[i];
            } else if(nums[i]>=mx2){
                mx3=mx2;
                mx2=nums[i];
            } else if(nums[i]>=mx3)
                mx3=nums[i];
            
            if(nums[i]<=mn1){
                mn2=mn1;
                mn1=nums[i];
            }
            else if(nums[i]<=mn2){
                mn2=nums[i];
            }
        }
        return max(mx1*mx2*mx3,mn1*mn2*mx1);
    }
};