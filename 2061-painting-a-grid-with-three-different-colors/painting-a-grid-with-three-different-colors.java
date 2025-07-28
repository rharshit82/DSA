class Solution {
    
    public int colorTheGrid(int m, int n) {
    //        Generate all valid colorings of a single column (no two adjacent cells in the column share the same color).
    // Two column-colorings can sit side by side if in every row their colors differ.
    // Then it’s just a DP over columns: let dp[k][s] be the number of ways to reach column k in state s.
       List<List<Integer>> states = new ArrayList<>();
       generateStates(0, m, states, new ArrayList<>());
       List<Integer>[] transitions = new ArrayList[states.size()];
       for(int i=0; i<states.size(); i++){
        transitions[i] = new ArrayList<>(); 
        for(int j=0; j<states.size(); j++){
            if(isCompatible(states.get(i), states.get(j))){
                transitions[i].add(j);
            }
        }
       }

       int[][] dp = new int[n][states.size()];
       for(int i=0; i<states.size(); i++){
        dp[0][i] = 1;
       }

       for(int i=1; i<n; i++){
        for(int j=0; j<states.size(); j++){
            for(int prev : transitions[j]){
                dp[i][j] = (dp[i][j] + dp[i-1][prev]) % 1_000_000_007;
            }
        }
       }
       int res= 0;
       for(int i=0; i<states.size(); i++){
         res = (res + dp[n - 1][i]) % 1_000_000_007;
       }
       return res;


    }

    boolean isCompatible(List<Integer> stateI, List<Integer> stateJ){
        for(int i=0; i<stateI.size(); i++){
            if(stateI.get(i) == stateJ.get(i)) return false;
        }
        return true;
    }

    void generateStates(int i, int m, List<List<Integer>> states, List<Integer> currState){
        if(currState.size() == m){
            states.add(new ArrayList<>(currState));
            return;
        }
        for(int color = 0; color < 3; color++){
            if(i>0 && currState.get(i-1) == color) continue;
            currState.add(color);
            generateStates(i+1, m, states, currState);
            currState.remove(currState.size() -1 );
        }
    }
}