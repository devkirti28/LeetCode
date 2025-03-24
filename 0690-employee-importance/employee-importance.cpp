/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,int> idToImp;
        unordered_map<int,vector<int>> subs;

        for(int i=0;i<employees.size();i++){
            idToImp[employees[i]->id] = employees[i]->importance;
            for(auto it:employees[i]->subordinates){
                subs[employees[i]->id].push_back(it);
            }
        }

        queue<int> q;
        q.push(id);
        int ans=0;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            ans+= idToImp[current];
            for(auto next : subs[current]){
                q.push(next);
            }
        }
        return ans;
    }
};