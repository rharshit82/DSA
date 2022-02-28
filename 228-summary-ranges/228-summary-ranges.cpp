class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        vector<string> res;
        while(i<n and j<n) {
            while(j+1<n and nums[j+1]==nums[j]+1) j++;
            if(nums[i] == nums[j])
                res.push_back(to_string(nums[i]));
            else
                res.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
            i = j+1, j = j+1;
        }
        return res;
    }
};