class Solution {
    class Pair{
        int node;
        double prob;
        public Pair(int node, double prob){
            this.node = node;
            this.prob = prob;
        }
    }
    public double maxProbability(int n, int[][] edges, double[] succProb, int src, int dst) {
        List<List<Pair>> graph = new ArrayList<>();
        for(int i=0; i<n; i++) graph.add(new ArrayList<>());
        for(int i=0; i<edges.length; i++){
            int[] edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            graph.get(u).add(new Pair(v, succProb[i]));
            graph.get(v).add(new Pair(u, succProb[i]));
        }
        double[] dist = new double[n];   
        Arrays.fill(dist, 0.0);

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Double.compare(b.prob,a.prob));
        pq.offer(new Pair(src, 1.0));

        while(!pq.isEmpty()){
            Pair curr = pq.poll();
            int node = curr.node;
            double prob = curr.prob;

            if(node == dst) return prob;
            for(Pair neighbour : graph.get(node)){
                int nnode = neighbour.node;
                double nprob = neighbour.prob;

                if(dist[nnode] < prob * nprob){
                    double newProb = prob * nprob;
                    dist[nnode] = prob * nprob;
                    pq.offer(new Pair(nnode, newProb));
                }
            }
        }
        return 0.0;
        
    }
}