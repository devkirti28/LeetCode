class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==1)return 1;
        unordered_map<char,int> m;
        int l=0,r=0,ans=0;
        while(r<s.size()) {
            if(m.find(s[r]) != m.end())l=max(l,m[s[r]]+1);
            ans=max(ans,r-l+1);
            m[s[r]]=r;
            r++;
        }
        return ans;
    }
};