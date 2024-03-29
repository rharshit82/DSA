class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int left=1;
        int lmax=INT_MIN;
        for(int i=0; i<n; i++){
            left= left*nums[i];
            lmax = max(lmax, left);
            if(left==0) left=1;
        }
        int right=1;
        int rmax=INT_MIN;
        for(int i=n-1; i>=0; i--){
            right= right*nums[i];
            rmax = max(rmax, right);
            if(right==0) right=1;
        }
        return max(lmax,rmax);
    }
};