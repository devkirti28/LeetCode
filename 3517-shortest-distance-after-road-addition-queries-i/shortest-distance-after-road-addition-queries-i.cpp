class Solution {
private: 
    int minDistance(vector<vector<int>>& adlist){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> distance(adlist.size(),1e9);
        distance[0]=0;
        // {distance, node}

        while(!pq.empty()){
            int currDistance = pq.top().first;
            int currNode  = pq.top().second;
            pq.pop();

            for(auto nextNode : adlist[currNode]){
                if(1 + currDistance < distance[nextNode]){
                    distance[nextNode] = 1 + currDistance;
                    pq.push({distance[nextNode], nextNode});
                }
            }
        }

        return distance[distance.size()-1];
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> adlist(n);
        
        for(int i=0;i<n-1;i++){
            adlist[i].push_back(i+1);
        }
        vector<int> answer;
        for(auto it: queries){
            int u = it[0];
            int v = it[1];
            adlist[u].push_back(v);
            answer.push_back(minDistance(adlist));
        }
        return answer;
    }
};