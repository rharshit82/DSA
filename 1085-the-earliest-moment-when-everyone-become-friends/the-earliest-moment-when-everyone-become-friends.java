class Solution {
    class UnionFind { 
        int[] parent;
        public UnionFind(int n){
            parent = new int[n];
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }

        public boolean union(int x, int y){
            int xRoot = find(x);
            int yRoot = find(y);
            if(parent[yRoot] == parent[xRoot]) return false;
            parent[xRoot] = yRoot;
            return true;
        }
        public int find(int x){
            int root = x;
            while(root!=parent[root]){
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
    public int earliestAcq(int[][] logs, int n) {
        Arrays.sort(logs, (a, b) -> Integer.compare(a[0], b[0]));
        UnionFind uf = new UnionFind(n);
        for(int[] log : logs){
            int ts = log[0];
            int x = log[1];
            int y = log[2];
            if(uf.union(x, y) == true) n--;
            if(n == 1) return ts;
        }
        return -1;
    }
}