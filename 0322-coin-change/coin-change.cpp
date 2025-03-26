class Solution {
    int r(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(i<0){
            if(amount==0)return 0;
            return 1e9;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int take = 1e9;
        if(coins[i]<=amount){
            take = 1 + r(i, amount-coins[i],coins,dp);
        }
        int notTake = r(i-1, amount, coins, dp);
        return dp[i][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans = r(n-1, amount, coins, dp);
        
        return (ans==1e9)? -1:ans;
    }
};