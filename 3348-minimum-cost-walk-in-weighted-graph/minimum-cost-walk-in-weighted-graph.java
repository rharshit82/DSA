class Solution {
    class UnionFind{
        int[] parent;
        public UnionFind(int n){
            parent = new int[n];

            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }

        public void union(int x, int y){
            int xRoot = find(x);
            int yRoot = find(y);

            if(xRoot!=yRoot){
                parent[xRoot] = yRoot;
            }
        }
        public int find(int x){
            int root = x;
            while(parent[root]!=root){
                root = parent[root];
            }

            while(x!=root){
                int next = parent[x];
                parent[x] = root;
                x = next;
            }
            return root;
        }
    }
    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        int[] minCost = new int[n];
        Arrays.fill(minCost, -1);
        UnionFind uf = new UnionFind(n);
        for(int[] edge : edges){
            int x = edge[0];
            int y = edge[1];
            int weight = edge[2];
            int xRoot = uf.find(x);
            int yRoot = uf.find(y);
            if(xRoot!=yRoot){
                uf.union(xRoot, yRoot);
                 int newRoot = uf.find(xRoot);
                int c1 = minCost[xRoot], c2 = minCost[yRoot];
                if(c1 == -1 && c2 == -1) minCost[newRoot] = weight;
                else if(c1 == -1) minCost[newRoot] = c2 & weight;
                else if(c2 == -1) minCost[newRoot] = c1 & weight;
                else minCost[newRoot] = c1 & c2 & weight;
            } else{
                if(minCost[yRoot]==-1){
                    minCost[yRoot] = weight;
                } else{
                    minCost[yRoot]&=weight;
                }
            }
        }
        int[] res = new int[query.length];
        int i = 0;
        for(int[] q : query) {
            int x = q[0];
            int y = q[1];
            int xRoot = uf.find(x);
            int yRoot = uf.find(y);
            if(xRoot!=yRoot){
                res[i] = -1;
            } else{
                res[i] = minCost[xRoot];
            }
            i++;
        }
        return res;
    }
}