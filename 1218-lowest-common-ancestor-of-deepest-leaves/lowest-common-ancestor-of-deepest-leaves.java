/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Result{
    int depth;
    TreeNode node;
    public Result(int _depth, TreeNode _node){
        depth = _depth;
        node = _node;
    }
}
class Solution {
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return findLca(root).node;
    }
    Result findLca(TreeNode root){
        if(root == null) return new Result(0, null);
        Result left = findLca(root.left);
        Result right = findLca(root.right);

        if(left.depth == right.depth){
            return new Result(left.depth + 1, root);
        } else if(left.depth > right.depth){
            return new Result(left.depth + 1, left.node);
        } 
        return new Result(right.depth+1, right.node);
    }
}