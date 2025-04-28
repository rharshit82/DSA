class Solution {
    class Pair{
        int node;
        int time;
        Pair(int _node, int _time){
            node = _node;
            time = _time;
        }
    }
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<Pair>> graph = new ArrayList<>();

        for(int i=0; i<=n; i++){
            graph.add(new ArrayList<>());
        }
        for(int[] time: times){
            int u = time[0];
            int v = time[1];
            int d = time[2];
            graph.get(u).add(new Pair(v, d));
        }

        int[] dis = new int[n+1];

        for(int i=0; i<=n; i++) dis[i] = Integer.MAX_VALUE;
        dis[k] = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.time));

        pq.offer(new Pair(k, 0));

        while(!pq.isEmpty()){
            Pair curr = pq.poll();
            int v = curr.node;
            int currW = curr.time;
            if(dis[v] < currW) continue;

            for(Pair neighbour : graph.get(v)){
                int u = neighbour.node;
                int w = neighbour.time;

                if(dis[u] > dis[v] + w){
                    dis[u] = dis[v] + w;
                    pq.offer(new Pair(u, dis[u]));
                }
            }
        }

        int res = 0;
        for(int i=1; i<=n; i++){
            if(dis[i] == Integer.MAX_VALUE) return -1;
            res = Math.max(res, dis[i]);
        }
        return res;
    }
}