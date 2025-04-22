class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp="";

        for(auto ch: s){
            if(ch==' '){
                if(temp.size()>0)
                    st.push(temp);
                temp="";
            }else{
                temp+=ch;
            }
        }
        if(temp.size()>0) 
            st.push(temp);

        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
            if(!st.empty())
                result+=' ';
        }
        return result;
    }
};