class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adlist(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto it: prerequisites){
            adlist[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();q.pop();
            topo.push_back(node);
            for(auto next : adlist[node]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        vector<int> empty;
        return (topo.size()==numCourses)? topo : empty;
    }
};