class Solution {
private:
    int findLength(int i, char ch, string& s){
        int length=0;
        while(i<s.size()){
            if(s[i++]==ch)break;
            length++;
        }
        return length;
    }
    int findLengthOfChars(int i, string& s){
        int length=0;
        while(i<s.size()){
            if(s[i]==']' || (s[i]-'0' >= 0 && s[i]-'9'<= 9) )break;
            i++;
            length++;
        }
        return length;
    }
    string decodeSubString(int num, string s){
        if(s.size()==1){
            char ch = s[0];
            string temp(num,ch);
            return temp;
        }
        string result="";
        while(num--){
            result+=s;
        }
        return result;
    }
public:
    string decodeString(string s) {

        // string num="", chars="", result="";
        // int i=0;
        // while(i<s.size()){
        //     // extract till [
        //     int length = findLength(i, '[', s);
            
        //     num = s.substr(i,length);
        //     i+= length+1;

        //     length = findLength(i, ']', s);
        //     chars = s.substr(i, length);
        //     i+= length+1;
        //     result+= decodeSubString(num , chars);
        // }
        // return result;

        stack<string> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ']') {
                string ans = "";
                while(st.top() != "[") {
                    ans = st.top() + ans;
                    st.pop();
                }
                st.pop();
                string times = "";
                while(!st.empty() && isdigit(st.top()[0])) {
                    times = st.top() + times;
                    st.pop();
                }
                int to_times = stoi(times);
                string ret = "";
                while(to_times--) {
                    ret = ans + ret;
                }
                st.push(ret);
            } else {
                string temp = s.substr(i,1);
                st.push(temp);
            }
        }
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};