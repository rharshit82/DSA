class Solution {
    public int maxEvents(int[][] events) {
        int n = events.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        int totalDays = 0;
        for(int[] event : events){
            totalDays = Math.max(totalDays, event[1]);
        }

        int res = 0;
        int i=0;
        int day = 1;
        while(i < n || !pq.isEmpty()){
            while(!pq.isEmpty() && pq.peek()[1] < day) pq.poll();
            while(i<n && events[i][0] <= day) {
                pq.offer(events[i]);
                i++;
            }
            if(!pq.isEmpty() && pq.peek()[1] >= day){
                res++;
                pq.poll();
            }
            day++;
        }
        
        return res;
    }
}