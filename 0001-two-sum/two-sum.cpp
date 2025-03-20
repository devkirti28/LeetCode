class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(mpp.count(target-nums[i])){
                ans.push_back(i);
                ans.push_back(mpp[target-nums[i]]); 
            }
            mpp[nums[i]]=i;
        }
        return ans;
    }
};