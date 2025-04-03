class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=-1,r=0,n=nums.size();
        int ans=0;
        while(r<n){
            if(nums[r]==1){
                ans = max(ans, r-l);
                r++;
            }else{
                l=r;
                r++;
            }
        }
        return ans;
    }
};