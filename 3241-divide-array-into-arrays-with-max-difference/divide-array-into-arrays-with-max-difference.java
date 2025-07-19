class Solution {
    public int[][] divideArray(int[] nums, int k) {
        int n = nums.length;
        int[][] res = new int[n/3][3];

        Arrays.sort(nums);

        for(int i=0; i<n; i+=3){
            if(i+2 < n && nums[i+2] - nums[i] >k) return new int[][]{};
        }
        for(int i=0; i<n; i++){
            res[(i/3)][i%3] = nums[i];
        }
        return res;
       
    }
}