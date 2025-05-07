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
        HashMap<Long, Integer> mp = new HashMap<>();
        mp.put(0L, 1);
        return traverse(root, targetSum, mp, 0);
    }
    int traverse(TreeNode root, int targetSum, HashMap<Long, Integer> mp, long currSum){
        if(root == null) return 0;
         currSum += root.val;
        int res= 0;
        res+= mp.getOrDefault(currSum - targetSum, 0);
        
        mp.put(currSum, mp.getOrDefault(currSum, 0) + 1);

        res+= traverse(root.left, targetSum, mp, currSum);
        res+= traverse(root.right, targetSum, mp, currSum);

        mp.put(currSum, mp.get(currSum) - 1);
        return res;

    }

}