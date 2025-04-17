class Solution {
    // int f(int l, int r, string& s1, string& s2){
    //     int n=s.size();
    //     if(l==0 || r==0){
    //         return 0;
    //     }

    //     if(s[l-1]==s[r-1]){
    //         return 1 + f(l-1,r-1, s1, s2);
    //     }
    //     return max(f(l-1,r,s1,s2), f(l,r-1,s1,s2));
    // }
public:
    string longestPalindrome(string s) {
        int start=0,maxl=0,n=s.size();
        for(int i=0;i<n;i++){
            //odd
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){

                if(r-l+1 > maxl){
                    maxl = r-l+1;
                    start = l;
                }
                l--;r++;
            }

            // even
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > maxl){
                    maxl = r-l+1;
                    start = l;
                }
                l--;r++;
            }
        }

        return s.substr(start,maxl);

    }
};