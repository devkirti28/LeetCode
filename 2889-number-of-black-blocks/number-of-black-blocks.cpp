class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> result(5,0);
        map<pair<int,int>,int> freqMap;
        for(auto coordinate : coordinates){
            int x = coordinate[0], y = coordinate[1];
            freqMap[{x,y}]++;
            freqMap[{x-1,y}]++;
            freqMap[{x,y-1}]++;
            freqMap[{x-1,y-1}]++;
        }
        long long total =  (long long)(m-1)*(long long)(n-1);
        int countNonZero=0;
        for(auto it:freqMap){
            int x = it.first.first, y = it.first.second;
            int freq = it.second;
            if(x>=0 && x<m-1 && y>=0 && y<n-1){
                result[freq]++;
                countNonZero++;
            }
        }
        result[0] = total - countNonZero;
        return result;
    }
};