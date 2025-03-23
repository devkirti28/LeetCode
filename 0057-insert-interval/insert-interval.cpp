class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newstart = newInterval[0];
        int newend = newInterval[1];
        int n=intervals.size();
        
        vector<vector<int>> answer;

        if(n==0){
            answer.push_back({newstart,newend});
            return answer;
        }
        int i=0;
        // all non overlapping intervals before new
        while(i<n && intervals[i][1] < newstart){
            answer.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        // need to add new interval
        while(i<n && newend >= intervals[i][0]){
            newstart = min(intervals[i][0],newstart);
            newend = max(newend,intervals[i][1]);
            i++;
        }
        answer.push_back({newstart, newend});
        // add remaining intervals
        while(i<n){
            answer.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        return answer;

    }
};