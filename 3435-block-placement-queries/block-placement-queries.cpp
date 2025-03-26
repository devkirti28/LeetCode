class FenwickTree{
    public:
    vector<int> bit;
    int n;
    FenwickTree(int n){
        this->n = n;
        bit.resize(n+1,0);
    }
    void add(int i,int val){
        while(i<=n){
            bit[i]=max(bit[i],val);
            i += (i& -i);
        }
    }
    int query(int i){
        int ans=0;
        while(i>0){
            ans = max(ans,bit[i]);
            i -= (i& -i);
        }
        return ans;
    }
};
class Solution {
private:
    bool canBePlaced(int maxPosition, int size, set<int> blocks){
        // [0,maxPosition]
        int left = 0;
        bool deleteLast = (blocks.find(maxPosition)==blocks.end());
        blocks.insert(maxPosition);
        for(auto it: blocks){
            if(it-left >= size){
                return true;
            }
            left=it;
            if(left==maxPosition)break;
        }
        if(deleteLast)blocks.erase(maxPosition);
        return false;
    }
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> blocks;
        vector<bool> result;
        // for(int i=0;i<queries.size();i++){
        //     if(queries[i][0]==1){
        //         blocks.insert(queries[i][1]);
        //     }else{
        //         result.push_back(canBePlaced(queries[i][1], queries[i][2], blocks));
        //     }

        // }

        int n = min(50000, ((int)queries.size()*3)) +1;
        blocks.insert(0);
        blocks.insert(n);
        FenwickTree fn(n);

        for(auto q:queries){
            if(q[0]==1){
                blocks.insert(q[1]);
            }
        }

        for(auto it=blocks.begin(); it!=blocks.end(); it++){
            if(it == blocks.begin())continue;
            auto prevIt = prev(it);
            int x = *it, prevVal = *prevIt;
            fn.add(x, x-prevVal);
        }


        for(int i=queries.size()-1; i>=0; i--){
            int type = queries[i][0];
            if(type==1){
                int x= queries[i][1];
                auto it = blocks.find(x);
                auto prevIt = prev(it);
                auto nextIt = next(it);
                blocks.erase(x);
                fn.add(*nextIt, *nextIt - *prevIt);
            }else{
                int x = queries[i][1];
                int size = queries[i][2];
                auto it = blocks.upper_bound(x);
                auto prevIt = prev(it);

                int maxSize = max(fn.query(*prevIt), x-*prevIt);
                result.push_back(maxSize>=size);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};