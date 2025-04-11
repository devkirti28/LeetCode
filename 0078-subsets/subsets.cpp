class Solution {
private:
    vector<vector<int>> ans;
    void f(int i,vector<int>&nums, vector<int>&temp){
        int n=nums.size();
        if(i==n){
            ans.push_back(temp);
            return;
        }
        f(i+1,nums,temp);
        temp.push_back(nums[i]);
        f(i+1,nums,temp);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        f(0,nums,temp);
        return ans;
    }
};