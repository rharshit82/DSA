class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates); 
        backtrack(candidates, 0, target, new ArrayList<>(), res);
        return res;
    }

     void backtrack(int[] candidates, int start, int target, List<Integer> curr, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(curr));
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;

            curr.add(candidates[i]);
            backtrack(candidates, i + 1, target - candidates[i], curr, res);
            curr.remove(curr.size() - 1);
        }
    }
}