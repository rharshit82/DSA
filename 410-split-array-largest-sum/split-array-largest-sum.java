class Solution {
    public int splitArray(int[] nums, int k) {
        int n = nums.length;

        int low = Arrays.stream(nums).max().getAsInt();
        int high = Arrays.stream(nums).sum();

        while(low <= high){
            int mid = low + (high-low)/2;
            if(canDo(mid, nums, k)){
                high = mid-1;
            } else {
                low = mid + 1;
            }
        }
        return high + 1;
    }
    boolean canDo(int mid, int[] nums, int k){
        int curSum = 0;
        int currK =  1;
        for(int i=0; i<nums.length; i++){
            if(curSum +nums[i] > mid){
                curSum = 0;
                currK++;
            }
            curSum+= nums[i];
        }
        return currK <= k;
    }
}
// [7,2,5,10,8]

// 