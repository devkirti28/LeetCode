class MyCalendar {
private:
    vector<vector<int>> intervals;

public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        bool ans=true;
        for(int i=0;i<intervals.size(); i++){
            int start = intervals[i][0], end =intervals[i][1];
            if(max(start,startTime) < min(end,endTime)){
                //overlap
                ans = false; 
                break;
            }
        }
        if(ans){
            cout<<startTime<<" "<<endTime<<endl;
            intervals.push_back({startTime, endTime});
        }
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */