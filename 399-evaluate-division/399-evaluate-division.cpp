class Solution {
    class Node{
        public: 
        string key; 
        double val;
        Node(string k, double v){
            key = k;
            val = v;
        }
    };
public:
    //build graph;
    map<string, vector<Node>> buildGraph(vector<vector<string>>& eq, vector<double>& values){
        map<string,vector<Node>> g;
        for(int i=0; i<values.size(); i++){
            string src = eq[i][0];
            string des = eq[i][1];
            g[src].push_back(Node(des,values[i]));
            g[des].push_back(Node(src,1/values[i]));
        }
        return g;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<Node>> g = buildGraph(equations, values);
        
        vector<double> res;
        for(int i=0; i<queries.size(); i++){
            set<string> visited;
            res.push_back(dfs(queries[i][0], queries[i][1],visited,g));
        }
        return res;
    }
    double dfs(string src, string des, set<string>&visited,map<string, vector<Node>>&g){
        if(g.find(src)==g.end() or g.find(des)==g.end()) return -1.0;
        if(src == des) return 1.0;
        visited.insert(src);
        for(auto it: g[src]){
            if(visited.find(it.key)==visited.end()){
                double ans = dfs(it.key,des,visited,g);
                if(ans!=-1.0){
                    return ans*it.val;
                }
            }
        }
        return -1.0;
    }
};