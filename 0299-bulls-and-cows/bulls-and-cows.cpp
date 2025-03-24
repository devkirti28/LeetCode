class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> guessHash(10,0), secretHash(10,0);
        int bull=0,cow=0;;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bull++;
                continue;
            }
            secretHash[secret[i]-'0']++;
            guessHash[guess[i]-'0']++;
        }
        for(int i=0;i<10;i++){
            cow+= min(secretHash[i],guessHash[i]);
        }
        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;
    }
};