class Solution {
    int r(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(i==0){
            if(amount==0)return 1;
            return 0;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int take = 0;
        if(coins[i-1]<=amount){
            take = r(i, amount-coins[i-1],coins,dp);
        }
        int notTake = r(i-1, amount, coins, dp);
        return dp[i][amount] = take + notTake;
    }
public:
    int change(int amount,vector<int>& coins ) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,-1));
        int ans = r(n, amount, coins, dp);
        return (ans==1e9)? 0:ans;
        
        // for(int i=0;i<=amount;i++){
        //     dp[0][i]=1e9;
        // }
        // dp[0][0]=0;

        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<=amount;j++){
        //         int take = 1e9;
        //         if(coins[i-1]<=j){
        //             take = 1 + dp[i][j-coins[i-1]];
        //         }
        //         int notTake = dp[i-1][j];
        //         dp[i][j] = min(take, notTake);
        //     }
        // }
        // return (dp[n][amount]==1e9)? -1: dp[n][amount];
    }
};