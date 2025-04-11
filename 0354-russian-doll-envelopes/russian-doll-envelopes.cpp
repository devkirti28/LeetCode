class Solution {
    private:
    int f(int i, int prev, vector<vector<int>>& env,vector<vector<int>>& dp){
        if(i==env.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];

        int len = f(i+1, prev, env,dp);
        if(prev==-1 || (env[prev][0] < env[i][0] && env[prev][1] < env[i][1])){
            len = max(len, 1 + f(i+1, i, env,dp));
        }
        return dp[i][prev+1] = len;
    }
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(), [](vector<int> a, vector<int>b){
            return (a[0]!=b[0])? a[0]<b[0] : a[1]>b[1];
        });
        int n=env.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return f(0,-1,env, dp);
        vector<int> temp;
        temp.push_back(env[0][1]);

        for(int i=1;i<n;i++){
            if(env[i][1]>temp.back()){
                temp.push_back(env[i][1]);
            }else{
                int ind = lower_bound(temp.begin(),temp.end(), env[i][1]) - temp.begin();
                temp[ind] = env[i][1];
            }
        }
        return temp.size();
    }
};