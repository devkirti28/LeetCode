class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())return findMedianSortedArrays(nums2,nums1);

        int s1 = nums1.size(), s2 = nums2.size();
        int leftElements = (s1+s2+1)/2;
        // 1,3, 5 6 -> 4 
        // 2, 4, 7, -> 3
        //  1,2,3,4,5,6,7
        // left = 4
        
        /*
        elements from num1 -> 0 - min(s1, left)
        1. 
        2       | 4, 7
        1,3,5   | 6

        2-
        2,4,    | 7
        1,3,    | 5,6

        l1=4
        l2=3
        r1=7
        r2=5
        */

        int low=0, high=s1;

        while(low<=high){
            int mid1 = (low+high)/2;
            int mid2 = leftElements - mid1;
            int l1 = (mid1-1>=0)?  nums1[mid1-1]: INT_MIN;
            int l2 = (mid2-1>=0)?  nums2[mid2-1]: INT_MIN;
            int r1 = (mid1 < s1)?  nums1[mid1]: INT_MAX;
            int r2 = (mid2 < s2)?  nums2[mid2]: INT_MAX;

            if(l1<=r2 && l2<=r1){
                //found valid division
                if((s1+s2)%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }else{
                    return (max(l1,l2));
                }
            }else if(l2>r1){
                low = mid1+1;
            }else{
                high = mid1-1;
            }
        }
        return -1;
    }
};