class MyCalendarTwo {
    private:
    // key -> startTime or EndTime 
    // value -> 1 / -1
        map<int,int> intervals;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        int maxBook=0;
        int ans=true;

        intervals[startTime]++;
        intervals[endTime]--;

        for(auto it: intervals){
            maxBook += it.second;
            if(maxBook>2){
                ans =false;
            } 
        }

        if(!ans){
            intervals[startTime]--;
            intervals[endTime]++;
        }
        return ans;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */