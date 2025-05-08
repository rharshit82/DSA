class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;

        Deque<Integer> st = new ArrayDeque<>();
        int[] res = new int[n];
        for(int i= n-1; i>=0; i--){
            while(!st.isEmpty() && st.peek() > prices[i]) st.pop();
            if(st.isEmpty()) res[i] = prices[i];
            else res[i] = prices[i] - st.peek();
            st.push(prices[i]);
        }
        return res;
    }
}