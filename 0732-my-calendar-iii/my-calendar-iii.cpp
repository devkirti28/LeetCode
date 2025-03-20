class MyCalendarThree {
    map<int,int> intervals;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        int maxBook=0;
        int ans=0;

        intervals[startTime]++;
        intervals[endTime]--;

        for(auto it: intervals){
            maxBook += it.second;
            ans = max(ans,maxBook);
        }

        // if(!ans){
        //     intervals[startTime]--;
        //     intervals[endTime]++;
        // }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */