class Solution {
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> combine(int n, int k) {
        

        List<Integer> curr = new ArrayList<>();
        traverse(1, n, k, curr);
        return res;
    }
    void traverse(int i, int n, int k, List<Integer> curr){
        if(curr.size() == k){
            res.add(new ArrayList<>(curr));
            return;
        }
        if(i > n) return;
        curr.add(i);
        traverse(i+1, n, k, curr);
        curr.remove(curr.size() - 1);
        traverse(i+1, n, k, curr);
    }
}