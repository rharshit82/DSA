class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        Deque<Integer> st = new ArrayDeque<>();
        int[] result = new int[n];
        int prevTime = 0;
        for(String log : logs){
            String[] parts = log.split(":");
            int fn = Integer.parseInt(parts[0]);
            int ts = Integer.parseInt(parts[2]);

            
            if(parts[1].equals("start")){
                if(!st.isEmpty()){
                    result[st.peek()] += ts - prevTime;
                }
                st.push(fn);
                prevTime = ts;
            } else{
                int fnToEnd = st.pop();
                result[fnToEnd] += ts - prevTime + 1;
                prevTime = ts+1;
            }
        }
        return result;
    }
}