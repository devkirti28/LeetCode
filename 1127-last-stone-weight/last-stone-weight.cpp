class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n==1)return stones[0];
        priority_queue<int> pq;
        for(auto w:stones){
            pq.push(w);
        }
        int stoneY, stoneX;
        while(!pq.empty()){
            stoneY = pq.top();pq.pop();
            if(pq.empty())return stoneY;
            stoneX = pq.top();pq.pop();
            if(stoneX==stoneY){
                continue;
            }
            if(stoneX < stoneY){
                pq.push(stoneY-stoneX);
            }
        }
        return 0; 
    }
};