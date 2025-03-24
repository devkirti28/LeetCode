class Solution {
    string checkDupSubstr(int l, string& s){
        unordered_map<int,int> freq;
        long long hash = 0, power=1;
        int mod = 1e9+7;
        int ind=0;
        while(ind<l){
            hash = (hash*31 + (s[ind]-'a' + 1))% mod ;
            if(ind>0)power=(power*31) % mod;
            ind++;
        }
        freq[hash] = 0;
        for(int i=1; i+l <= s.size(); i++){
            hash = (hash - ((s[i-1]-'a'+ 1)*power)%mod + mod) % mod;
            hash = (hash*31)%mod;
            hash = (hash + (s[i+l-1]-'a'+1))%mod;
            if(freq.find(hash)!=freq.end() && (s.substr(freq[hash], l) == s.substr(i, l))){

                return s.substr(freq[hash], l);
            }
            freq[hash]=i;
        }
        return "";
    }
public:
    string longestDupSubstring(string s) {
        int low = 0, high = s.size();
        int len=0; string ans;
        while(low<=high){
            int mid = (low + high)/2;
            string temp = checkDupSubstr(mid, s);
            if(temp.size()!=0){
                if(mid>len){
                    len = mid;
                    ans = temp;
                }
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        if(high==-1)return "";
        return ans;
    }
};