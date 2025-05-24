/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
}
*/

class Solution {
    public Node construct(int[][] grid) {
        int n = grid.length;
        Node res = dfs(grid, 0, 0, n);
        return res;
    }

    Node dfs(int[][] grid, int i, int j, int size){
        if(isUniform(grid, i, j, size)){
            return new Node(grid[i][j] == 1, true);
        }

        int half = size/2;
        Node topLeft = dfs(grid, i, j, half);
        Node topRight = dfs(grid, i, j+half, half);
        Node bottomLeft = dfs(grid, i+half, j, half);
        Node bottomRight = dfs(grid, i+half, j+half, half);

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    boolean isUniform(int[][] grid, int r, int c, int size){
        for(int i=r; i<r+size; i++){
            for(int j=c; j<c+size; j++){
                if(grid[i][j]!=grid[r][c]) return false;
            }
        }
        return true;
    }
}