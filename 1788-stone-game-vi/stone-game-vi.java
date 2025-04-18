class Solution {
    public int stoneGameVI(int[] alice, int[] bob) {
        int n= alice.length;
        int[][] comp = new int[n+1][3];


for (int i = 0; i < n; i++) {
    comp[i][0] = alice[i] + bob[i];
    comp[i][1] = alice[i];
    comp[i][2] = bob[i];
}


        Arrays.sort(comp, (a, b) -> b[0] - a[0]);
        int a=0, b=0;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                a+=comp[i][1];
            } else{
                b+=comp[i][2];
            }
        }


        if (a > b) return 1;
        else if (a < b) return -1;
        else return 0; 
    }
}