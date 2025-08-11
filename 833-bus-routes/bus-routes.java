class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        // approach : instead of stops, use buses. 
        // since we can visit one stop again and again, 
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int n = routes.length;
        for(int i=0; i<routes.length; i++){
            int[] bus = routes[i];
            for(int stop : bus){
                adj.computeIfAbsent(stop, k -> new ArrayList<>()).add(i);
            }
        }
        if(source == target) return 0;
        if(!adj.containsKey(source) || !adj.containsKey(target)) return -1;
        boolean[] visited = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        for(int bus : adj.get(source)){
            visited[bus] = true;
            q.offer(bus);
        }
        int busesTaken = 1;
        while(!q.isEmpty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int curBus = q.poll();
                for(int stop : routes[curBus]){
                    if(stop == target) return busesTaken;
                    for(int nextBus : adj.get(stop)){
                        if(!visited[nextBus]){
                            q.offer(nextBus);
                            visited[nextBus] = true;
                        }
                    }
                }
            }
            busesTaken++;
        }
        return -1;

    }
}