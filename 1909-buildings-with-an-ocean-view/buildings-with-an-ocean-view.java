class Solution {
    public int[] findBuildings(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int n = heights.length;
        List<Integer> arr = new ArrayList<>();
        for(int i=n-1; i>=0; i--){
            while(!st.isEmpty() && st.peek() < heights[i]) st.pop();

            if(st.isEmpty()) arr.add(i);
            st.push(heights[i]);
        }
        return arr.stream().sorted().mapToInt(i -> i).toArray();
    }
}