class Solution {
public:
    int bsearch(vector<int>& nums, int x){
        int low = 0, high =nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==x) return mid;
            if(nums[mid]>x){
                high=mid-1;
            } else{
                low = mid+1;
            }
        }
        return -1;
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res=0;
        int cur=1;
        int last=INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i]==last) continue;
            if(bsearch(nums,nums[i]+1)!=-1){
                cur++;
            } else{
                cur=1;
            }
            last = nums[i];
            res = max(res, cur);
        }
        return res;
    }
};