class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        Deque<Integer> st = new ArrayDeque<>();
        int n = heights.length;

        int[] res = new int[n];

        res[n-1] = 0;
        st.push(heights[n-1]);
        for(int i = n-2; i>=0; i--){
            int count = 0;
            while(!st.isEmpty() && heights[i] > st.peek()){
                count++;
                st.pop();
            }
            if(!st.isEmpty()) count++;
            res[i] = count;
            st.push(heights[i]);
        }
        return res;
    }
}