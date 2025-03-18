class Solution {
private: 
    vector<int> count;
    void merge(vector<int>& count, vector<pair<int,int>>& nums, int low, int mid, int high){

        //[low ... mid]
        //[mid+1, ... high]
        // if nums[low] > nums[mid+1] -> count+= mid-low+1

        vector<pair<int,int>> temp;
        int left = low;
        int right = mid+1;
        int smallerElementsRight=0;

        while(left<=mid && right<=high){
            if(nums[left].first<=nums[right].first){
                temp.push_back(nums[left]);
                count[nums[left].second] += smallerElementsRight;
                left++;
            }else{
                temp.push_back(nums[right]);
                smallerElementsRight++;
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            count[nums[left].second] += smallerElementsRight;
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            nums[i] = temp[i-low];
        }
    }
    void ms(vector<int>& count, vector<pair<int,int>>& nums, int low, int high){
        if(low==high)return;

        int  mid = (low+high)/2;
        ms(count, nums,low, mid);
        ms(count, nums, mid+1, high);
        merge(count, nums, low, mid, high);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(n,0);
        vector<pair<int,int>> num(n);
        for(int i=0;i<n;i++){
            num[i]={nums[i],i};
        }
        ms(count, num, 0, n-1);
        return count;
    }
};