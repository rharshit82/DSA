class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> dict = new HashSet<>(wordList);
        List<List<String>> res = new ArrayList<>();
        if (!dict.contains(endWord)) return res;

        Map<String, List<String>> parents = new HashMap<>();
        Set<String> visited = new HashSet<>();
        Queue<String> q = new LinkedList<>();
        q.offer(beginWord);
        visited.add(beginWord);
        boolean found = false;

        while (!q.isEmpty() && !found) {
            Set<String> visitedThisLevel = new HashSet<>();
            int size = q.size();

            for (int i = 0; i < size; i++) {
                String word = q.poll();
                char[] arr = word.toCharArray();

                for (int j = 0; j < arr.length; j++) {
                    char original = arr[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        arr[j] = c;
                        String next = new String(arr);

                        if (dict.contains(next)) {
                            if (!visited.contains(next)) {
                                if (!visitedThisLevel.contains(next)) {
                                    q.offer(next);
                                    visitedThisLevel.add(next);
                                }
                                parents.computeIfAbsent(next, k -> new ArrayList<>()).add(word);
                            }
                            if (next.equals(endWord)) {
                                found = true;
                            }
                        }
                    }
                    arr[j] = original;
                }
            }
            visited.addAll(visitedThisLevel);
        }

        if (found) {
            List<String> path = new ArrayList<>();
            path.add(endWord);
            backtrack(res, path, parents, beginWord, endWord);
        }
        return res;
    }

    private void backtrack(List<List<String>> res, List<String> path,
                           Map<String, List<String>> parents, String beginWord, String word) {
        if (word.equals(beginWord)) {
            List<String> copy = new ArrayList<>(path);
            Collections.reverse(copy);
            res.add(copy);
            return;
        }
        if (!parents.containsKey(word)) return;
        for (String p : parents.get(word)) {
            path.add(p);
            backtrack(res, path, parents, beginWord, p);
            path.remove(path.size() - 1);
        }
    }
}
