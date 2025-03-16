class Solution {
private:
    bool dfs(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i<0 && j<0)return true;
        if(j<0) return false;
        if(i<0){
            while(j>=0){
                if(p[j]!='*')return false;
                j--;
            }
            return true;
        }


        if(dp[i][j]!=-1)return dp[i][j];
        bool result=false;
        if(p[j]!= '?' && p[j]!= '*'){
            result = (p[j]==s[i])? dfs(i-1, j-1, s, p, dp) : false;
        }
        if(p[j]=='?'){
           result =  dfs(i-1, j-1, s, p, dp);
        }
        if(p[j]=='*'){
           result =  (dfs(i-1, j, s, p, dp) || dfs(i-1, j-1, s, p, dp) || dfs(i, j-1, s, p, dp));
        }
        return dp[i][j] = result;
    }
public:
    bool isMatch(string s, string p) {
        // * -> any sequence including empty
        // ? -> any char

        // s-> abcdef 
        // p-> *    T
        // p-> a*a  F
        // p-> *?   T
        // p-> abc  F
        // p-> ab?c F
        // p-> abc?e* T

        /*
        2 pointers for traversing the 2 strings
        match at each position for lowercase letters
        for ? :
            one char is matched
        for * : 
            1. match and increment s poniter
            2. increment only p pointer
        */
        int sSize = s.size();
        int pSize = p.size();
        vector<vector<int>> dp (sSize, vector<int> (pSize,-1));
        return dfs(s.size()-1, p.size()-1, s, p, dp);
    }
};