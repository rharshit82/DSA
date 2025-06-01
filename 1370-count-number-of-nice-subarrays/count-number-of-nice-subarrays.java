class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k-1);
    }
    int atMostK(int[] nums, int k){
        int n = nums.length;
        int low = 0;
        int oddCount = 0;
        int res = 0;
        for(int high = 0; high<n; high++){
            if(nums[high]%2 != 0) oddCount++;
            while(oddCount > k){
                if(nums[low]%2 != 0) oddCount--;
                low++;
            }
            res+= high-low + 1;
        }
        return res;
    }
}