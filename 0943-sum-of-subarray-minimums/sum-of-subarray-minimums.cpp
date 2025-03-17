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
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int mod = 1e9 + 7;
        int answer=0;
        for(int i=0;i<arr.size();i++){
            long int left =  (nse[i]-i);
            long int right = (i-pse[i]);
            long int rep = (left* right * arr[i])% mod;
            answer= (answer + rep) % mod;
        }
        return answer;
    }
};