class Solution {
    class Pair{
        int node;
        long time;
        public Pair(int node, long time){
            this.node = node;
            this.time = time;
        }
    }
    public int countPaths(int n, int[][] roads) {
        int res = 0;
        List<List<Pair>> graph = new ArrayList<>();
        for(int i=0; i<n; i++) graph.add(new ArrayList<>());
        for(int[] road : roads){
            int u = road[0];
            int v = road[1];
            int t = road[2];
            graph.get(u).add(new Pair(v, t));
            graph.get(v).add(new Pair(u, t));
        }

        int[] ways = new int[n];
        Arrays.fill(ways, 0);

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Long.compare(a.time ,b.time));

        long[] dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        ways[0] = 1;
        pq.offer(new Pair(0, 0));

        while(!pq.isEmpty()){
            Pair curr = pq.poll();
            long t = curr.time;
            int currNode = curr.node;

            for(Pair nb : graph.get(currNode)){
                int u = nb.node;
                long ct = nb.time;
                if(dist[u] > t + ct){
                    dist[u] = t + ct;
                    ways[u] = ways[currNode];
                    pq.offer(new Pair(u, dist[u]));
                } else if(dist[u] == t + ct){
                    ways[u] = (ways[u] + ways[currNode])%1000000007;
                }
            }
        }
        return ways[n-1];
    }
}