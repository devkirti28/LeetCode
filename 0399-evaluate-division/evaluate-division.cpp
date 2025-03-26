class Solution {
    void dfs(unordered_map<string, unordered_map<string,double>> adlist, unordered_set<string> visited, double& ans, double temp, string node, string target){
        if(visited.find(node)!=visited.end())return;
        visited.insert(node);
        if(node==target){ 
            ans=temp;
            return;
        }
        for(auto it : adlist[node]){
            dfs(adlist, visited, ans, temp*it.second, it.first, target);
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, unordered_map<string,double>> adlist;
        for(int i=0;i<n;i++){
            adlist[equations[i][0]][equations[i][1]] = values[i];
            adlist[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }

        int m = queries.size();
        vector<double> result(m);
        for(int i=0;i<m;i++){
            unordered_set<string> visited;
            double ans = -1.0;
            double temp = 1.0;
            string source = queries[i][0];
            string target = queries[i][1];
            if(adlist.find(source)==adlist.end() || adlist.find(target)==adlist.end()){
                result[i]=ans;
                continue;
            }
            dfs(adlist, visited, ans, temp, source, target);
            result[i]=ans;
        }
        return result;
    }
};