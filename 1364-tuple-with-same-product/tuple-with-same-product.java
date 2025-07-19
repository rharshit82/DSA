class Solution {
    public int tupleSameProduct(int[] nums) {
        int n = nums.length;
        int res = 0;
        Map<Integer, Integer> products = new HashMap<>();
        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int product = nums[i]*nums[j];
                if(products.containsKey(product)){
                    res+= products.get(product);
                }
                products.put(product, products.getOrDefault(product, 0) + 1);
            }
        }
        return 8*res;

    }
}