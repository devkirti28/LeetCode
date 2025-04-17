class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,l=0,r=0,n=s.size();
        unordered_map<char, int> freq;

        while(r<n){
            if(freq[s[r]]>=1){
                freq[s[l]]--;
                l++;
            }else{
                freq[s[r]]++;
                ans= max(ans, r-l+1);
                r++;
            }
        }
        return ans;
    }
};