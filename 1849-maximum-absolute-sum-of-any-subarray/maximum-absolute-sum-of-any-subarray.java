class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int n = nums.length;
        int minSum = 0, maxSum = 0;
        int minEndingHere = 0, maxEndingHere = 0;
        int curr = 0;
        for(int num : nums){
            curr+= num;
            minEndingHere = Math.min(num, minEndingHere + num);
            minSum = Math.min(minSum, minEndingHere);

            maxEndingHere = Math.max(num, maxEndingHere + num);
            maxSum = Math.max(maxSum, maxEndingHere);
        }
        return Math.max(Math.abs(minSum), Math.abs(maxSum));
    }
}