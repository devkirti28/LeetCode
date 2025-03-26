class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX, maxi = INT_MIN;
        int ans=0;

        for(auto p : prices){
            
            maxi = max(p,maxi);
            if(p<min){
                min = p;
                maxi = p;
            }
            
            if(ans<maxi-min)ans=maxi-min;
        }
        return ans;
    }
};