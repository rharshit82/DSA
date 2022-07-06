class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int target = -nums[i];
            int j=i+1, k=n-1;
            while(j<k){
                if((nums[j]+nums[k])<target){
                    j++;
                } else if((nums[j]+nums[k])>target){
                    k--;
                } else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    res.push_back(temp);
                    while(j<n and nums[j]==temp[1]) j++;
                    while(k>=0 and nums[k]==temp[2]) k--;
                }
            }
            while(i+1<n and nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};