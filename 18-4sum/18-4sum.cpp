class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(long long i=0; i<n; i++){
            long long target3 = target - nums[i];
            for(long long j=i+1; j<n; j++){
                long long target2= target3 - nums[j];
                long long low = j+1, high = n-1;
                while(low<high){
                    long long sum = nums[low]+nums[high];
                    if(sum>target2){
                        high--;
                    } else if(sum<target2){
                        low++;
                    } else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        res.push_back(temp);
                        while(low<n and nums[low]==temp[2]) low++;
                        while(high>=0 and nums[high]==temp[3]) high--;
                    }
                }
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
            while(i+1<n and nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};