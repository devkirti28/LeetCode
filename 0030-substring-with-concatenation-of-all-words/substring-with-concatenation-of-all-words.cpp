class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordlength = words[0].size();
        int num = words.size();

        unordered_map<string, int> wordMap, curr;
        for (auto w : words) {
            wordMap[w]++;
        }
        vector<int> ans;
        // s is the string we will iterate over, checking each substring of
        // length wordLength*num
        int sublength = wordlength * num;
        if(s.size()<sublength)return ans;
        
        for(int i=0;i<wordlength;i++){
            int left=i, right = i;
            int count=0;
            curr = wordMap;
            while(right + wordlength <=  s.size()){
                string word = s.substr(right, wordlength);
                right+= wordlength;

                if(wordMap.count(word)){
                    count++;
                    curr[word]--;
                    
                    while(curr[word]<0){
                        string leftWord = s.substr(left, wordlength);
                        curr[leftWord]++;
                        count--;
                        left+= wordlength;
                    }
                    if(count==num){
                        ans.push_back(left);
                    }
                }else{
                    left = right;
                    count=0;
                    curr=wordMap;
                }
            }
        }
    
        return ans;
    }
};