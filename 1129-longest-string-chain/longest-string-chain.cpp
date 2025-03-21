class Solution {

private:
    // a.size() > b.size()
    bool isValidChain(string a, string b){
        int bigger = 0, count=0; 
        if(a.size() != b.size()+1)return false;

        for(int i=0;i<b.size();i++,bigger++){
            if(a[bigger]!=b[i]){
                count++;
                if(count>1)
                    return false;
                i--;
            }
        }
        return (count==1 || bigger == b.size());
    }
    // solve(n-1, -1, words)
    int solve(int i, int p, vector<string>& words, vector<vector<int>>& dp){
        if(i<0){
            return 0;
        }
        if(dp[i][p]!=-1)return dp[i][p];
        int select = INT_MIN;
        if(p==words.size() || isValidChain(words[p], words[i])){
            select = 1 + solve(i-1, i , words, dp);
        }
        int skip = solve(i-1, p, words, dp);

        return dp[i][p] = max(select,skip);
    }
public:
    int longestStrChain(vector<string>& words) {
        // a b ba bca bda bdca 
        // different options at each position 
        // 1. select a word (we need its index)
        //  a. if a word is selected previously, 
        //   current word should differ in lenght 
        //   by one and have all other chars same 
        //  b. no word selected previously, any word can be selected
        // 2. do not select a word
        // function to return max lenght
        sort(words.begin(),words.end(), [](string a, string b){
            return a.size()<b.size();
        });
        for(auto w:words)cout<<w<<" ";
        cout<<endl;
        int n = words.size();
        // vector<vector<int>> dp(n, vector<int> (n+1, -1));
        // return solve(n-1, n, words, dp);


        unordered_map<string,int> dp;
        int maxLength=0,best=0;

        for(auto word:words){
            best=0;
            for(int i=0;i<word.size();i++){
                string prev = word.substr(0,i) + word.substr(i+1);
                best = max(best,dp[prev]);
            }
            dp[word] = 1 + best;
            maxLength = max(maxLength, dp[word]);
        }
        return maxLength;
    }
};