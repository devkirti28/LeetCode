class Solution {
private:
    bool isValid(int i, int j, int m, int n){
        return (i>=0 && i<m && j>=0 && j<n);
    }

public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(); // <=40
        if(k>= m+n-3)return m+n-2;
        // start -> (0,0)  || end -> (m-1,n-1) || 0 
        int drow[] = {0,0,-1,1};
        int dcol[] = {-1,1,0,0};
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},k});
        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int> (k+1, 0)));
        vis[0][0][k]=1;
        int steps=0;
        while(!q.empty()){
            int size = q.size();
            for(int k=0;k<size;k++){
                int row = q.front().first.first;
                int col = q.front().first.second;
                int currK = q.front().second;
                q.pop();
                
                if(row == m-1 && col == n-1){
                    return steps;
                }
                for(int i = 0; i<4;i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(isValid(nrow,ncol,m,n) && !vis[nrow][ncol][currK]){
                        if(grid[nrow][ncol]==0){
                            q.push({{nrow,ncol},currK});
                            vis[nrow][ncol][currK] =1;
                        }else if(currK>0){
                            q.push({{nrow,ncol},currK-1});
                            vis[nrow][ncol][currK-1] =1;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};