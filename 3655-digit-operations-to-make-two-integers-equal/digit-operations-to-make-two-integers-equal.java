class Solution {
    public int minOperations(int n, int m) {
if (isPrime(n)) return -1;
        Set<Integer> visited = new HashSet<>();
        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));

        pq.offer(new long[]{n,n}); // cost, number
        while(!pq.isEmpty()){
            long[] curr = pq.poll();
            long currCost = curr[0];
            int number =  (int) curr[1];
            if(number == m) return (int)currCost;
            if(visited.contains(number)) continue;
            visited.add(number);
            char[] num = String.valueOf(number).toCharArray();
            int[] delta = new int[]{1, -1};
            for(int i=0; i<num.length; i++){
                char ch = num[i];
                int letter = ch-'0';
                for(int d : delta){
                    int newLetter = letter + d;
                    if (newLetter < 0 || newLetter > 9) continue; 
                    char[] clonedNum = num.clone();
                    clonedNum[i] = (char)(newLetter + '0');
                    int newNumber =  Integer.parseInt(new String(clonedNum));
                    if(!isPrime(newNumber) && !visited.contains(newNumber)){
                        
                        pq.offer(new long[]{currCost + newNumber, newNumber});
                    }
                }
            }
            
        }
return -1;
    }

    boolean isPrime(int n){
        if (n < 2) return false;
        if(n == 2) return true;
        if(n%2 == 0) return false;
        for(int i=3; i*i <=n; i+=2){
            if(n%i == 0) return false;
        }
        return true;
    }
}