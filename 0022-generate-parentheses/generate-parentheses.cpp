class Solution {
private:
vector<string> ans;
    void f(int o, int c, string& s){
        if(o==0 && c==0){
            ans.push_back(s);
        }
        // (
        if(o>0){
            s.push_back('(');
            f(o-1,c,s);
            s.pop_back();
        }
        // )
        if(c>o && c>0){
            s.push_back(')');
            f(o,c-1,s);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s="";
        f(n,n,s);
        return ans;
    }
};