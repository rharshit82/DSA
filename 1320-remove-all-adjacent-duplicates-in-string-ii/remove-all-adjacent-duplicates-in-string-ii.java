class Solution {
      class Node {
        Character ele;
        Integer count;
        public Node(Character ele, Integer count){
            this.ele = ele;
            this.count = count;
        }
    }
    public String removeDuplicates(String s, int k) {
         Stack<Node> st = new Stack<>();
        StringBuilder res = new StringBuilder();

        for(int i=0; i<s.length(); i++){
            Character curr = s.charAt(i);
            if(!st.isEmpty()){
                Node top = st.peek();
                if(top.ele == curr){
                    int currCount = top.count+1;
                    if(currCount == k){
                        int kCounterForLoop = k - 1;
                        while(!st.isEmpty() && kCounterForLoop-- > 0){
                            st.pop();
                        }
                    } else{
                        st.push(new Node(top.ele, currCount));
                    }
                } else{
                    st.push(new Node(curr, 1));
                }
                
            } else{
                st.push(new Node(curr, 1));
            }
        }
        while(!st.isEmpty()){
            res.append(st.pop().ele);
        }
        return res.reverse().toString();
  
    }
}