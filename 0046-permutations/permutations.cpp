class Solution {
private:
 vector<vector<int>> ans;
    void f(vector<int>& freq, vector<int>& temp, vector<int>& nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(freq[i]==0){
                freq[i]++;
                temp.push_back(nums[i]);
                f(freq,temp,nums);
                temp.pop_back();
                freq[i]--;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> freq(nums.size(),0);
        vector<int> temp;
        f(freq, temp, nums);
        return ans;
    }
};