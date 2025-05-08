class Solution {
    public int[] dailyTemperatures(int[] temp) {
        int n = temp.length;
        Deque<Integer> st = new ArrayDeque<>();
        int[] res = new int[n];
        for(int i= n-1; i>=0; i--){
            int curr = temp[i];
            while(!st.isEmpty() && temp[st.peek()] <= curr) st.pop();
            if(st.isEmpty()) res[i] = 0;
            else res[i] =  st.peek() - i ;
            st.push(i);
        }
        return res;
    }
}