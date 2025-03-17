class Solution {
    bool validSubstring( unordered_map<char,int>& freq){
        return (freq['a']>0 && freq['b']>0 && freq['c']>0);
    }
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> freq;
        vector<int> last = {-1,-1,-1};
        int count=0;
        for(int i=0;i<s.size();i++){
            last[s[i]-'a'] = i;
            count += 1 + min({last[0],last[1],last[2]});
        }
        return count;
    }
};