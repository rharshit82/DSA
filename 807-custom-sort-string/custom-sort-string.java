class Solution {
    public String customSortString(String order, String s) {
        StringBuilder res = new StringBuilder();
        Map<Character, Integer> mp = new HashMap<>();
        for(char ch : s.toCharArray()){
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }
        for(char ch : order.toCharArray()){
            if(mp.containsKey(ch)){
 res.append(String.valueOf(ch).repeat(mp.get(ch)));
            }
            mp.remove(ch);
        }
        for(Character ch : mp.keySet()){
            res.append(String.valueOf(ch).repeat(mp.get(ch)));
        }
        return res.toString();
    }
}