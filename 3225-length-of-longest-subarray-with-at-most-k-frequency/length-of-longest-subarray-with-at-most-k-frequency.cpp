class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int l=0,r=0,maxLength=0,maxfreq=0;

        while(r<nums.size()){
            freq[nums[r]]++;
            maxfreq = max(maxfreq,freq[nums[r]]);
            if(maxfreq<=k){
                maxLength = max(maxLength, r-l+1);
            }else{
                int maxNum = nums[r];
                while(nums[l]!=maxNum){
                    freq[nums[l]]--;
                    l++;
                }
                freq[nums[l++]]--;
                maxfreq--;
            }
            r++;
        }
        return maxLength;
    }
};