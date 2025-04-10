class MyCalendarThree {
private:
    map<int,int> booked;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        booked[startTime]++;
        booked[endTime]--;
        int count=0, maxCount=0;
        bool tripleBooking=false;
        for(auto time : booked){
            count+= time.second;
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */