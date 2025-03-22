class Solution {
    bool canCover(vector<int>& houses, vector<int>& heater, int r){
        int houseIndex=0;
        int heaterIndex=0;

        while(houseIndex<houses.size() && heaterIndex<heater.size()){
            if(heater[heaterIndex]-r <= houses[houseIndex] && heater[heaterIndex]+r >= houses[houseIndex]){
                houseIndex++;
            }else{
                heaterIndex++;
            }
        }
        return houseIndex==houses.size();
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int l=0; int r=INT_MAX;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans=0;
        while(l<=r){
            int mid = (l+r)/2;
            if(canCover(houses,heaters,mid)){
                r=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};