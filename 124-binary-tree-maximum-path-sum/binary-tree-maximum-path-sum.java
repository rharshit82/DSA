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
class Solution {
    public int maxPathSum(TreeNode root) {
        int[] curr = new int[]{Integer.MIN_VALUE};
        dfs(root, curr);
        return curr[0];
    }
    int dfs(TreeNode root, int[] curr){
        if(root == null) return 0;
        int left = Math.max(0, dfs(root.left, curr));
        int right = Math.max(0, dfs(root.right, curr));
        curr[0] = Math.max(curr[0], left + right + root.val);

        return root.val + Math.max(left, right);
    }
}