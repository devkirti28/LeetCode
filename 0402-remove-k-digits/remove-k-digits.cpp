class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string ans="";
        ans.push_back(num[0]);
        for(int i=1;i<num.size();i++){
            while(!ans.empty() && ans.back() > num[i] and k>0){
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
        }
        cout<<ans<<endl;

        while(k>0){
            ans.pop_back();
            k--;
        }

        int i=0;
        while(i<ans.size()){
            if(ans[i]!='0')break;
            i++;
        }

        string final = ans.substr(i);

        return (final.size()==0)? "0":final;
    }
};