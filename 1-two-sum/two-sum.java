class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i=0; i<n; i++){
            int otherPair = target - nums[i];
            if(mp.containsKey(otherPair)){
                return new int[]{mp.get(otherPair), i};
            }
            mp.put(nums[i], i);
        }
        return new int[]{0,0};
    }
}