class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int> , greater<int>> minHeap;
public:
    MedianFinder() { 
    }
    void addNum(int num) {
        maxHeap.push(num);
        if(maxHeap.size()-minHeap.size() > 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(!minHeap.empty() && !maxHeap.empty() && maxHeap.top()>minHeap.top()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            return (maxHeap.top()+minHeap.top())/2.0;
        }else{
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */