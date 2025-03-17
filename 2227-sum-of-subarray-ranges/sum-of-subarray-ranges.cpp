class Solution {
private:
    vector<int> findNSE(vector<int>& arr){
        vector<int> nse(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = (!st.empty())? st.top() : arr.size();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSE(vector<int>& arr){
        vector<int> pse(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = (!st.empty())? st.top() : -1;
            st.push(i);
        }
        return pse;
    }
    vector<int> findNGE(vector<int>& arr){
        vector<int> nge(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            nge[i] = (!st.empty())? st.top() : arr.size();
            st.push(i);
        }
        return nge;
    }
    vector<int> findPGE(vector<int>& arr){
        vector<int> pge(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            pge[i] = (!st.empty())? st.top() : -1;
            st.push(i);
        }
        return pge;
    }
    long long  sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        long long  answer=0;
        for(int i=0;i<arr.size();i++){
            long int left =  (nse[i]-i);
            long int right = (i-pse[i]);
            long int rep = (left* right * arr[i]);
            answer= (answer + rep);
        }
        return answer;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> nge = findNGE(arr);
        vector<int> pge = findPGE(arr);
        long long answer=0;
        for(int i=0;i<arr.size();i++){
            long int left =  (nge[i]-i);
            long int right = (i-pge[i]);
            long int rep = (left* right * arr[i]);
            answer= (answer + rep);
        }
        return answer;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));
    }
};