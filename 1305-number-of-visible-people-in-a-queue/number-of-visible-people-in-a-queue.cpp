class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st; 
        int vis=0;

        for(int i=n-1;i>=0;i--){
            int h = heights[i];
            vis=0;
            // if(st.empty()){
            //     ans[i]=vis;
            // }
            while(!st.empty() && h > st.top()){
                vis++;
                st.pop();
            }

            vis = (st.empty())? vis : vis+1;
            ans[i]=vis;

            st.push(heights[i]);
        }
        return ans;
    }
};