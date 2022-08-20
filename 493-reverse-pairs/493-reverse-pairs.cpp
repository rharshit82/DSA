class Solution {
public:
    void merge(int start, int mid, int end, vector<int>&nums, int& res){
        int i = start, j = mid+1;
        while(i<=mid and j<=end){
            if((long)nums[i]>(long)2*nums[j]){
                res+= mid-i+1;
                j++;
            } else{
                i++;
            }
        }
        sort(nums.begin()+start, nums.begin()+end +1);
    }
    void mergeSort(int start, int end, vector<int>&nums, int& res){
        if(start == end) return;
        int mid = start+ (end-start)/2;
        mergeSort(start, mid, nums, res);
        mergeSort(mid+1, end, nums, res);
        merge(start, mid, end, nums, res);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        int res=0;
        mergeSort(0, n-1, nums, res);
        return res;
    }
};