class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int target = -nums[i];
            int low = i+1;
            int high = n-1;
            while(low<high){
                int sum = nums[low] + nums[high];
                if(sum>target) high--;
                else if(sum<target) low++;
                else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    res.push_back(temp);
                    while(low<high and nums[low]==temp[1]) low++;
                    while(low<high and nums[high]==temp[2]) high--;
                }
            }
            while(i+1<n and nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};