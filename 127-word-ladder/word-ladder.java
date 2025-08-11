class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        int n = wordList.size();
        Set<String> wordsSet = new HashSet<>(wordList);

        Queue<String> q = new LinkedList<>();
        q.offer(beginWord);
        if (beginWord.length() != endWord.length())
            return 0;
        int steps = 1;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                String curr = q.poll();
                if (curr.equals(endWord))
                    return steps;

                for (int i = 0; i < curr.length(); i++) {
                    for (int j = 0; j < 26; j++) {
                        char newChar = (char) ('a' + j);
                        if (newChar == curr.charAt(i))
                            continue;
                        char[] curChars = curr.toCharArray();
                        curChars[i] = newChar;
                        String newString = String.valueOf(curChars);
                        if (wordsSet.contains(newString)) {
                            q.offer(newString);
                            wordsSet.remove(newString);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
}