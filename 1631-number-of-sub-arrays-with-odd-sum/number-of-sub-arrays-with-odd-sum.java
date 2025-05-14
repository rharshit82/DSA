class Solution {
    public int numOfSubarrays(int[] arr) {
        int n = arr.length;
        final int MOD = 1000000007;

        int curr = 0;
        int odd_c = 0;
        int even_c = 1;
        int res = 0;
        for(int i=0; i<n; i++){
            curr+= arr[i];
            if(curr%2 == 0){
                even_c++;
                res = (res+odd_c)%MOD;
            } else{
                odd_c++;
                res = (res+even_c)%MOD;
            }
        }
        return res;
    }
}