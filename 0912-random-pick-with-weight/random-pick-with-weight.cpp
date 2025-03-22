class Solution {
    vector<int> pre;
    int sum;
public:
    Solution(vector<int>& w) {
        for(int i=0;i<w.size();i++){
            pre.push_back(w[i] + ((i==0)? 0 : pre[i-1]));
        }
        sum = pre[w.size()-1];
    }
    
    int pickIndex() {
        int lower=1 , upper = sum;
        int randomInRange = lower + (rand() % (upper - lower + 1));

        for(int i=0;i<pre.size();i++){
            if(randomInRange <= pre[i]){
                return i;
            }
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */