class StockPrice {
    unordered_map<int,int> mpp;
    multiset<int> s;
    int currPrice,maxTime;
public:
    StockPrice() {
        currPrice=0;
        maxTime=0;
    }
    
    void update(int timestamp, int price) {
        if(mpp.count(timestamp)){
            s.erase(s.find(mpp[timestamp]));
        }
        mpp[timestamp]=price;
        s.insert(price);
        if(timestamp>=maxTime){
            maxTime = timestamp;
            currPrice = price;
        }
    }
    
    int current() {
        return currPrice;
    }
    
    int maximum() {
        int ans=INT_MIN;
        auto it = s.rbegin();
        ans=max(ans,*it);
        return ans;
    }
    
    int minimum() {
        int ans=INT_MAX;
        auto it = s.begin();
        ans=min(ans,*it);
        return ans;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */