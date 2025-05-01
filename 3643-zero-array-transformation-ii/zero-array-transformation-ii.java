class Solution {
    public int minZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int qlength = queries.length;
        int low = 0, high = qlength;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(canZero(mid, nums, queries)){
                high = mid-1;
            } else low = mid+1;
        }
        return low == qlength +1? -1 : low;
    }

    boolean canZero(int k, int[] nums, int[][] queries){
        int[] tmp = Arrays.copyOf(nums, nums.length);
        int[] diff = new int[nums.length+2];
        Arrays.fill(diff, 0);
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l]-=val;
            diff[r+1]+= val;
        }
        int curr = 0;
        for(int i=0; i<tmp.length; i++){
            curr += diff[i];
            tmp[i] += curr;
            if(tmp[i] > 0) return false;
        }
       
        return true;
    }
}