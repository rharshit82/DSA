class Solution {
public:
    int start(vector<int>&nums,int target){
        int n=nums.size();
        int low = 0, high=n-1;
        int res=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>target) high= mid-1;
            else if(nums[mid]<target) low = mid+1;
            else{
                high=mid-1;
                res=mid;
            }
        }
        return res;
    }
    int end(vector<int>&nums,int target){
        int n=nums.size();
        int low = 0, high=n-1;
        int res=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>target) high= mid-1;
            else if(nums[mid]<target) low = mid+1;
            else{
                low = mid+1;
                res=mid;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(start(nums,target));
        res.push_back(end(nums,target));
        return res;
    }
};