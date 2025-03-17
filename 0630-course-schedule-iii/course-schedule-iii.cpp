bool comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
class Solution {
    
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int totalTime=0;

        sort(courses.begin(),courses.end(),comp);

        priority_queue<int> pq;
        int count=0;
        for(int i=0;i<courses.size();i++){
            if(totalTime + courses[i][0] <= courses[i][1]){
                totalTime += courses[i][0];
                pq.push(courses[i][0]);
                count++;
            }else{
                if(pq.empty())continue;
                int maxDuration = pq.top(); 
                if(maxDuration > courses[i][0] && totalTime - maxDuration + courses[i][0] <= courses[i][1]){
                    pq.pop();
                    totalTime += (-maxDuration + courses[i][0]);
                    pq.push(courses[i][0]);
                }
            }
        }

        return count;
    }
};