class Solution {
    public int[] getOrder(int[][] tasks) {
        int n = tasks.length;
        int[][] tasksWithIdx = new int[n][3];
        for(int i=0; i<n; i++){
            tasksWithIdx[i][0] = tasks[i][0];
            tasksWithIdx[i][1] = tasks[i][1];
            tasksWithIdx[i][2] = i;
        }
        Arrays.sort(tasksWithIdx, (a, b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] == b[1] ? Integer.compare(a[2], b[2]) : Integer.compare(a[1], b[1]));
        int[] result = new int[n];
        int idx = 0;
        int time = 0;
        int taskIndex = 0;
        while(idx < n){
            while(taskIndex < n && time >= tasksWithIdx[taskIndex][0]){
                pq.offer(tasksWithIdx[taskIndex++]);
            }

            if(pq.isEmpty()) {
                time = tasksWithIdx[taskIndex][0];
                continue;
            }

            int[] task = pq.poll();
            result[idx++] = task[2];
            time+= task[1];
        }


        return result;
    }
}