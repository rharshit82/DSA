class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int res = 0;

        int n = nums.length;
        long sum = 0;
        int left = 0;
        for(int right=0; right<n; right++){
            sum+= nums[right];
            long cost = nums[right] * (right-left+1) - sum;
           while ((long) nums[right] * (right - left + 1) - sum > k) {
    sum -= nums[left];
    left++;
}
            res = Math.max(res, right-left + 1);
        }
        return res;
    }
}