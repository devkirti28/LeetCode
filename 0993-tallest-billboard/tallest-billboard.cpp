class Solution {
private:
    //solve(n-1, 0,0,rods)
    void solve(int i, int s1, int s2, int& ans, vector<int>& rods){
        if(s1==s2 && s1>ans){
            ans = s1;
        }
        if(i<0){
            return;
        }

        solve(i-1, s1+rods[i], s2, ans, rods);
        solve(i-1, s1, s2+rods[i], ans, rods);
        solve(i-1, s1, s2, ans, rods);
    }

    int solveOp(int i, int diff, int& ans, vector<int>& rods, vector<vector<int>>& dp){
        if(i<0){
            if(diff==0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i][diff+5000]!=-1)return dp[i][diff+5000];

        int s1 = rods[i] + solveOp(i-1, diff+rods[i], ans, rods,dp);
        int s2 = solveOp(i-1, diff-rods[i], ans, rods,dp);
        int d = solveOp(i-1, diff, ans, rods,dp);
        return dp[i][diff+5000] = max({s1,s2,d});
    }
public:
    int tallestBillboard(vector<int>& rods) {
        /*
        [1,20] -> 1 rod gives answer 0
        1000
        sum max 20,000
        s1 and s2 and discard
        max s1 and s2 while s1==s2
        -- 
        greedy not possible
        --
        s1,s2,d
        n number of rods
        3^n
        ---
        s1
        s2-> sum - (s1+d)


        */
        //diff range-> [-5000, 5000]-> using 5000 offset -> [0,10,000]
        vector<vector<int>> dp(21,vector<int>(10000, -1));

        int ans=0;
        ans = solveOp(rods.size()-1,0,ans, rods,dp);
        return ans;
    }
};