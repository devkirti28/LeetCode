class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> freq;
        int count=0;

        for(auto n:time){
            int num = n % 60;
            int comp = (60-num) % 60;
            cout<<comp<<endl;
            if(freq.find(comp)!=freq.end()){
                count+=freq[comp];
            }
            freq[num]++;
        }
        return count;
    }
};