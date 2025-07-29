class Solution {
    public int singleNumber(int[] nums) {
        int[] bits = new int[32];
        Arrays.fill(bits, 0);
        for(int i=0; i<nums.length; i++){
            for(int j=0; j<32; j++){
                if((nums[i] & (1<<j)) != 0) bits[j]++;
            }
        }

        int res = 0;
        for(int i=0; i<32; i++){
            res+= (bits[i]%3) * 1<<i;
        }
        return res;
    }
}