class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n =nums.size();
        if(n < 3) return ans; 
        sort(nums.begin(),nums.end());
           
        for(int i =0;i<n;i++)
        {
           if(i>0 && nums[i]==nums[i-1]){
               continue;
           }
            if(nums[i]>0){
                break;
            }
            int l=i+1,r=nums.size()-1;
            
            while(l<r){
                if(nums[l]+nums[r]+nums[i] == 0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    int val=nums[l];
                    while(l<r && nums[l]==val){
                        l++;
                    }
                } else if(nums[l]+nums[r]+nums[i] < 0){
                    l++;
                } else{
                    r--;
                }
            }
        }
        return ans;
        
    }
};