class Solution {
public:
    int reverse(int x) {
        // x = abs(x);
        long int rev=0;
        while(x!=0){
            int temp = x%10;
            rev = rev*10 + temp;
            x/=10;
        }
        if(rev<INT_MIN || rev>INT_MAX)return 0;
        return rev;
    }
};