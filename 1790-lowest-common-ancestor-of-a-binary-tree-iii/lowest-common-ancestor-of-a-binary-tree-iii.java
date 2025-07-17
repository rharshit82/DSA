/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
};
*/

class Solution {
    public Node lowestCommonAncestor(Node p, Node q) {
        Set<Integer> st = new HashSet<>();

        while(p!= null) {
            st.add(p.val);
            p = p.parent;
        }
        while(q!=null){
            if(st.contains(q.val)) return q;
            q = q.parent;
        }

        return null;
    }

   
}