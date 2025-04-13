class Solution {
    public String smallestNumber(String pattern) {
        int n = pattern.length();
        StringBuilder res = new StringBuilder();
        Deque<Integer> st = new ArrayDeque<>();

        for (int i = 1; i <= n + 1; i++) {
            st.push(i);

              if (i == n + 1 || pattern.charAt(i - 1) == 'I') {
                while (!st.isEmpty()) {
                    res.append(st.pop());
                }
            }
        }

        return res.toString();
    }
}