class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int i = low; i<=high; i++){
            String num = Integer.toString(i);
            if(num.length()%2 !=0) continue;
            if(countSum(num) == true) res++;
        }
        return res;
    }
    boolean countSum(String s){
        int sum = 0;
        int n = s.length();
        int i = 0;
        for(char ch: s.toCharArray()){
            if(i < n/2){
                sum+= Character.getNumericValue(ch);
            }else sum-=Character.getNumericValue(ch);
            i++;
        }
        return sum == 0;
    }
}