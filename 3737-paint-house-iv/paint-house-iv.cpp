class Solution {
private:
    long long solve(int i, int prev, int prev2, vector<vector<int>>& cost,vector<vector<vector<long long>>>& dp){
        int n = cost.size();
        if(i==n/2){
            return 0;
        }
        if(dp[i][prev+1][prev2+1]!=-1)return dp[i][prev+1][prev2+1];

        long long minCost = LLONG_MAX;
        for(int j=0;j<3;j++){
            if(j==prev)continue;
            for(int k=0;k<3;k++){
                if(k==j || k==prev2)continue;
                long long option = cost[i][j] + cost[n-i-1][k] + solve(i+1,j,k,cost,dp);
                minCost = min(minCost,option);
            }
        }   
        return dp[i][prev+1][prev2+1] = minCost;
    }

public:
    long long minCost(int n, vector<vector<int>>& cost) {
        // total of 3 options
        // at index i -> 
        //1. color should be different from i-1 --- Ex. n=5 i=1  diff from i-1 = 0
        //2. color should be different from n-i-1 --- diff from n-i-1 = 4
        // index, prev color selected

        vector<vector<vector<long long>>> dp(n / 2, vector<vector<long long>>(4, vector<long long>(4, -1)));
        return solve(0,-1,-1,cost,dp);
    }
};