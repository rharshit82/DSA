class Solution {
public:
    long long canDo(vector<int>&nums, int x){
        long long sum = 0;
        for(auto ele: nums){
            sum+= abs(ele-x);
        }
        return sum;
    }
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        int low = *min_element(nums.begin(),nums.end());
        int res = -1;
        while(low<=high){
            int mid = low+ (high-low)/2;
            int a = canDo(nums,mid);
            int b = canDo(nums,mid+1);
            if(a<b){
                res = a;
                high = mid-1;
            } else{
                res= b;
                low = mid+1;
            }
        }
        return res;
    }
};