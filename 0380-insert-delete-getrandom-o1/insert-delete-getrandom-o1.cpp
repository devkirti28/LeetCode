class RandomizedSet {
    unordered_set<int> s;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.count(val)>0){
            return false;
        }else{
            s.insert(val);
        }
        return true;
    }
    
    bool remove(int val) {
        if(s.count(val)==0){
            return false;
        }else{
            s.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        int n=s.size();
        int random = rand()%n; //[0,n-1]
        auto it = s.begin();
        advance(it,random);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */