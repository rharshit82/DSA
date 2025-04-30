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
    public TreeNode bstToGst(TreeNode root) {
        if(root == null) return root;

        helper(root, 0);
        return root;
    }
    int helper(TreeNode root, int sum) {
        if(root == null) return sum;

        int currSum = helper(root.right, sum);
        root.val+= currSum;

        return helper(root.left, root.val);

    }
}