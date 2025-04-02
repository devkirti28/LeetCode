class Solution {
private:
    // solve(0, 0, -1)
    int solve(int ind, int count, int prevColor, vector<int>& houses, vector<vector<int>>& cost, int target, vector<vector<vector<int>>>& dp){
        int m = houses.size();
        int n = cost[0].size();
        if(ind==m){
            return (count==target)? 0 : INT_MAX;
        }

        if(dp[ind][count][prevColor+1] != -1){
            return dp[ind][count][prevColor+1];
        }

        int houseCost = INT_MAX;
        int minHouseCost = INT_MAX;
        if(houses[ind]!=0){
            int newCount = (houses[ind]-1 == prevColor)? count : count+1;
            if(newCount <= target){
                minHouseCost = solve(ind + 1, newCount, houses[ind]-1, houses, cost, target, dp);
            }
        }else{
            for(int j=0;j<n;j++){
                int newCount = (j == prevColor)? count : count+1;
                houseCost=INT_MAX;
                if(newCount <= target){
                    houseCost = solve(ind + 1, newCount, j, houses, cost, target, dp);
                }
                if(houseCost != INT_MAX)
                    minHouseCost =  min(minHouseCost, cost[ind][j] + houseCost);
            }
        }
        return dp[ind][count][prevColor+1] = minHouseCost;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // m houses -> only houses which are not painted have to be painted 
        // same adjacent houses make a neighbourhood
        // min cost to paint [0] houses to make target neighbourhoods
        // index , neighbourhoods, prevHouseColor
        vector<vector<vector<int>>> dp (m, vector<vector<int>> (target+1, vector<int> (n+1,-1)));
        int ans = solve(0,0,-1,houses,cost,target,dp);
        return (ans==INT_MAX)? -1 :ans;
    }
};