class Solution {
    public boolean isThree(int n) {
        boolean flag = false;

        for(int i=2; i<=n-1; i++){
            if(n%i == 0){
                if(n/i!=i) return false;
                flag = true;
            }
        }
        return flag;
        
    }
}