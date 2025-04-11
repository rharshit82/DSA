class Solution {
    int[] majorityElement(List<Integer> nums) {
        int mj = -1;
        int count = 0;
        for(int ele : nums){
            if (count == 0) {
    mj = ele;
    count = 1;
}

            else if(ele == mj){
                count++;
            } else {
                count--;
            }
            
        }
        int freq = 0;
        for (int num : nums) {
            if (num == mj) freq++;
        }
        return new int[]{mj, freq};
    }
    public int minimumIndex(List<Integer> nums) {
        int[] mjEleRes = majorityElement(nums);
        int mjEle = mjEleRes[0];
        int count = mjEleRes[1];
        int currCount = 0;
        int n = nums.size();
        for(int i= 0; i<n - 1; i++){
            int ele = nums.get(i);
            if(ele == mjEle){
                currCount++;
            }

            int left = currCount;
            int right = n - left;
           if (currCount * 2 > (i + 1) && (count - currCount) * 2 > (n - i - 1)) {
    return i;
}
        }
        
        return -1;

    }
}