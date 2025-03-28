class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int left = 0, right=0;
        unordered_map<char,int> indexMap;
        int ans = 0;
        while(right<size){
            char ch = s[right];
            if(indexMap.find(ch)!=indexMap.end() && indexMap[ch]>=left){
                left = indexMap[ch] + 1;
            }
            indexMap[ch]=right;
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};