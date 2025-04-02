class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for(int i=1;i<strs.size();i++){
            int minSize = min(prefix.size(), strs[i].size());
            prefix = prefix.substr(0, minSize);
            for(int j=0;j<minSize;j++){
                if(prefix[j] != strs[i][j]){
                    prefix = prefix.substr(0, j);
                    break;
                }
            }

        }
        return prefix;
    }
};