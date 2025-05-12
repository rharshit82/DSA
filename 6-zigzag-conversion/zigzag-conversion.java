class Solution {
    public String convert(String s, int numRows) {
        int n = s.length();
        if (numRows == 1) return s;

        StringBuilder[] res = new StringBuilder[Math.min(numRows, n)];
        for(int i=0; i<res.length; i++) res[i] = new StringBuilder();
        int cycle = 2 * numRows - 2;
        for(int i=0; i<n; i++){
            int curr = i % cycle;
            int row = curr < numRows ? curr : cycle - curr;
            res[row].append(s.charAt(i));
        }
        StringBuilder finalres = new StringBuilder();
        for(int i=0; i<res.length; i++) finalres.append(res[i]);
        
        return finalres.toString();
    }
}