class MyCalendarTwo {
private:
    map<int,int> booked;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        booked[startTime]++;
        booked[endTime]--;
        int count=0;
        bool tripleBooking=false;
        for(auto time : booked){
            count+= time.second;
            if(count>2){
                tripleBooking=true;
                break;
            }
        }
        if(tripleBooking){
            booked[startTime]--;
            booked[endTime]++;
            return false;
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */