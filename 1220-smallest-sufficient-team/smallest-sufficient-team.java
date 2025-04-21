class Solution {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        int n = req_skills.length;
        Map<String, Integer> skillIndex = new HashMap<>();
        for(int i=0; i<n; i++){
            skillIndex.put(req_skills[i], i);
        }

        int[] peopleMasks = new int[people.size()];
        for (int i = 0; i < people.size(); i++) {
            int mask = 0;
            for(String skill : people.get(i)){
                if(skillIndex.containsKey(skill)){
                    mask |= (1 << skillIndex.get(skill));
                }
            }
            peopleMasks[i] = mask;
        }

        HashMap<Integer, List<Integer>> dp = new HashMap<>();
        dp.put(0, new ArrayList<>());
        for(int i=0; i<people.size(); i++){
            int currentPerson = peopleMasks[i];
            HashMap<Integer, List<Integer>> cur = new HashMap<>(dp);
            for(int existingMask : cur.keySet()){
                int combinedMask = existingMask | currentPerson;
                
                if(!dp.containsKey(combinedMask) || dp.get(combinedMask).size() > cur.get(existingMask).size() + 1) {
                    ArrayList<Integer> a = new ArrayList<>(dp.get(existingMask));
                    a.add(i);
                    dp.put(combinedMask, a);
                }
            }
        }
        int required = (1 << n) - 1;
        List<Integer> req = dp.get(required);
        return req.stream().mapToInt(i -> i).toArray();
    }
}