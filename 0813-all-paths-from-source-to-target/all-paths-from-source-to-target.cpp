class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void dfs(int node, vector<vector<int>>& adlist){
        int n=adlist.size();
        path.push_back(node);
        if(node==n-1){
            result.push_back(path);
        }
        for(auto nextNode : adlist[node]){
            dfs(nextNode, adlist);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        dfs(0,graph);
        return result;
    }
};