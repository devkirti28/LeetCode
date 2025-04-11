class Solution {
private:
    int recursion(int step, vector<int>& dp){
        if(step<=1)return 1;
        if(dp[step]!=-1)return dp[step];
        int count = recursion(step-1, dp) + recursion(step-2, dp);
        return dp[step] = count;
    }
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return recursion(n,dp);
        vector<int> dp(n+1,0);
        dp[0]=1;dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};