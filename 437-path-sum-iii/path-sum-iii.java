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
    public int pathSum(TreeNode root, int targetSum) {
        return pathSum(root, (long) targetSum);
    }

    public int pathSum(TreeNode root, long targetSum) {
        if(root == null) return 0;

        return pathSum(root.left, targetSum ) + pathSum(root.right, targetSum ) + countWaysFrom(root, targetSum);
    }

    int countWaysFrom(TreeNode root, long targetSum){
        if(root == null) return 0;
        int res = 0;
        if(root.val == targetSum) res++;

        return res + countWaysFrom(root.left, targetSum-root.val) + countWaysFrom(root.right, targetSum-root.val);
    }

}