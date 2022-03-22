class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int res = nums[0]+nums[1]+nums[n-1];
        for(int i=0; i<n-2; i++){
            int low = i+1;
            int high = n-1;
            while(high>low){
                int curr_sum = nums[i]+nums[low]+nums[high];
                if(abs(curr_sum-target)<abs(res-target)){
                    res=curr_sum;
                }
                if(curr_sum>target) high--;
                else low++;
            }
        }
        return res;
    }
};