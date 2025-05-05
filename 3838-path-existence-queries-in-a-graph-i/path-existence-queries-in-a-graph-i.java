class Solution {
    class UnionFind{
        int[] parent;
        public UnionFind(int n){
            parent = new int[n];
            for(int i=0; i<n; i++) parent[i] = i;
        }
        public void union(int x, int y){
            int a = find(x);
            int b = find(y);

            if(a == b) return;
            parent[a] = b;
        }

        public int find(int x){
            int root = x;

            while(root!=parent[root]){
                root = parent[root];
            }

            while(x!=root){
                int prev = parent[x];
                parent[x] = root;
                x = prev;
            }
            return x;
        }
    }
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = nums[i];
            arr[i][1] = i;      
        }

        Arrays.sort(arr, Comparator.comparingInt(a -> a[0]));
        UnionFind uf = new UnionFind(n);
        for(int i=1; i<n; i++){
            if(arr[i][0] - arr[i-1][0] <=maxDiff) uf.union(arr[i][1], arr[i-1][1]);
        }
        boolean[] res = new boolean[queries.length];
        int i = 0;
        for(int[] query : queries) {
            
            int u = query[0];
            int v = query[1];
            res[i] = uf.find(u) == uf.find(v);
            i++;
        }
        return res;
    }
}