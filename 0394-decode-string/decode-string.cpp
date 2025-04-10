class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        int n=s.size();
        int i=0;

        while(i<n){
            if(s[i]==']'){
                string repeatString = "";
                while(!st.empty() && st.top()!='['){
                    repeatString = st.top() + repeatString;
                    st.pop();
                }
                st.pop();
                string repeatNumber = "";
                while(!st.empty() && isdigit(st.top())){
                    repeatNumber = st.top() + repeatNumber;
                    st.pop();
                }
                int repeats = stoi(repeatNumber);
                string repeatedString = "";
                while(repeats--){
                    repeatedString+=repeatString;
                }
                int j=0;
                int tempLength=repeatedString.size();
                while(j<tempLength){
                    st.push(repeatedString[j++]);
                }
            }else{
                st.push(s[i]);
            }
            i++;
        }
        string result="";
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};