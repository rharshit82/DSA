class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        int res = 0;
        HashMap<Integer,Integer> mp  = new HashMap<>();
        int i = 0;
        int sum = 0;
        for(int j=0; j<n; j++){
            sum+= nums[j];
            if(mp.containsKey(nums[j])){
                while(mp.containsKey(nums[j])){
                    sum-= nums[i];
                    if(mp.get(nums[i]) > 1) mp.put(nums[i], mp.get(nums[i]) - 1);
                    else mp.remove(nums[i]);
                    i++;
                }
            }
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            res = Math.max(res, sum);
        }
        return res;
    }
}