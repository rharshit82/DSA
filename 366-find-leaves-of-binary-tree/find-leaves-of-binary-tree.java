class Solution {
    public List<List<Integer>> findLeaves(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();

        while (root != null) {
            List<Integer> curr = new ArrayList<>();
            root = removeLeaves(root, curr); // ✅ update root
            res.add(curr);
        }

        return res;
    }

    private TreeNode removeLeaves(TreeNode node, List<Integer> curr) {
        if (node == null) return null;

        if (node.left == null && node.right == null) {
            curr.add(node.val);
            return null; // ✅ remove leaf
        }

        node.left = removeLeaves(node.left, curr);
        node.right = removeLeaves(node.right, curr);
        return node;
    }
}
