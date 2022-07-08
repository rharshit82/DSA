class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int res = 1e8;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            int left=i+1, right = n-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(abs(sum-target)<abs(target-res)){
                    res = sum;
                }
                if(nums[i]+nums[left]+nums[right]>target){
                    right--;
                } else{
                    left++;
                }
                
            }
        }
        return res;
    }
};