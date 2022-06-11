class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            int target=-nums[i];
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum = nums[left] + nums[right];
                if(sum<target){
                    left++;
                } else if(sum>target){
                    right--;
                } else{
                    res.push_back({nums[i],nums[left],nums[right]});
                    int j=left;
                    int k=right;
                    while(left<right and nums[j]==nums[left]) left++;
                    while(right>left and nums[k]==nums[right]) right--;
                }
            }
            while(i+1<n and nums[i+1]==nums[i]) i++;
        }
        return res;
        
    }
};