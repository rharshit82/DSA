class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Set<String> suppliesSet = new HashSet<>(Arrays.asList(supplies));
        Map<String, List<String>> ingredientsRecipesMap = new HashMap<>();
        Map<String, Integer> indegreeMap = new HashMap<>();
        
        for(int i=0; i<recipes.length; i++){
            indegreeMap.put(recipes[i], 0);
            for(int j=0; j<ingredients.get(i).size(); j++){
                String ingredient = ingredients.get(i).get(j);
                indegreeMap.put(recipes[i], indegreeMap.get(recipes[i]) + 1);
                ingredientsRecipesMap.computeIfAbsent(ingredient, k -> new ArrayList<>()).add(recipes[i]);
            }
            
        }

        Queue<String> q = new LinkedList<>(suppliesSet);
        List<String> res = new ArrayList<>();
        while(!q.isEmpty()){
            String currRecipe = q.poll();
            
            if(!ingredientsRecipesMap.containsKey(currRecipe)) continue;
            for(String recipe : ingredientsRecipesMap.get(currRecipe)){
                int existingDegree = indegreeMap.get(recipe);
                existingDegree--;
                if(existingDegree == 0){
                    res.add(recipe);
                    indegreeMap.remove(recipe);
                    q.add(recipe);
                } else{
                    indegreeMap.put(recipe, existingDegree);
                }
            }
        }
        return res;
    }
}