class Solution {
    public long countSubarrays(int[] nums, int k) {
        long n = nums.length;
        int low = 0, high = 0, maxOcc = 0;
        long maxi = Arrays.stream(nums).max().getAsInt();
        long res = 0;
        while(high < n){
            if(nums[high++] == maxi) maxOcc++;

            while(maxOcc>=k && low <high){
                if(nums[low++] == maxi) maxOcc--;
            }
            res+= low;
        }
        return res;
    }
}