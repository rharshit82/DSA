class Solution {
    public class UnionFind{
        int[] parent;
        int[] rank;
        UnionFind(int n){
            parent = new int[n];
            rank = new int[n];
            Arrays.fill(parent, -1);
            
        }
        public boolean union(int x, int y){
            int xRoot = find(x);
            int yRoot = find(y);

            if(xRoot == yRoot) return false;
           if (rank[xRoot] > rank[yRoot]) {
                parent[yRoot] = xRoot;
            } else if (rank[xRoot] < rank[yRoot]) {
                parent[xRoot] = yRoot;
            } else {
                parent[yRoot] = xRoot;
                rank[xRoot]++;
            }
            return true;
        }

        public int find(int x){
    int root = x;
    while (parent[root] != root) {
        root = parent[root];
    }

    while (x != root) {
        int next = parent[x];
        parent[x] = root;
        x = next;
    }

    return root;
}

    }

    boolean isValid(int m, int n, int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    public List<Integer> numIslands2(int m, int n, int[][] positions) {
        List<Integer> result = new ArrayList<>();
        UnionFind uf = new UnionFind(m * n);
        int[] dirsX = {1, 0, 0, -1};
        int[] dirsY = {0, 1, -1, 0};
        int count = 0;
        for(int[] position : positions){
            int x = position[0];
            int y = position[1];
            int p = x* n + y;

            if(uf.parent[p]!=-1){
                result.add(count);
                continue;
            }

            uf.parent[p] = p;
            count++;
            for(int i=0; i<4; i++){
                int nX = x + dirsX[i];
                int nY = y + dirsY[i];
                if(isValid(m, n, nX, nY)){
                    int q = nX * n + nY;
                    if(uf.parent[q]!=-1 && uf.union(p, q)){
                        count--;
                    }
                }
            }
            result.add(count);
        }

        return result;
    }
}