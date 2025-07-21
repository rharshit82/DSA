class Solution {
    public int numSubseq(int[] nums, int target) {
        int n = nums.length;
        int res= 0;
        Arrays.sort(nums);
        int[] pow2 = new int[n];
        pow2[0] = 1;
        final int MOD = 1_000_000_007;
        for(int i=1; i<n; i++){
            pow2[i] = (int)(1L* pow2[i-1] << 1) % MOD;
        }
        for(int low = 0; low<n; low++){
            int high = n-1;
            int left = low, right = high;
            int validHigh = -1;
            while(left <= right ){
                int mid = left + (right-left)/2;
                if(nums[low] + nums[mid] <= target){
                    validHigh = mid;
                    left = mid+1;
                } else right = mid-1;
            }
            if(validHigh>=low){
                res=  (res+pow2[validHigh-low])%MOD;
            }
        }
        return res;
    }
}