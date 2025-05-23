class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> res = new ArrayList<>();
        int n = nums.length;
        for(int i=0; i<l.length; i++){
            int left = l[i];
            int right = r[i];
            boolean curr = checkArithmeticSub(nums, left, right);
            res.add(curr);
        }
        return res;
    }
    boolean checkArithmeticSub(int[] nums, int l, int r){
        List<Integer> temp = new ArrayList<>();
        for(int i=l; i<=r; i++){
            temp.add(nums[i]);
        }
        Collections.sort(temp);
        if(temp.size() <= 2) return true;
       int diff = temp.get(1) - temp.get(0);
        for (int i = 2; i < temp.size(); i++) {
            if (temp.get(i) - temp.get(i - 1) != diff) return false;
        }
        return true;
    }
}