class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.insert(wordList.begin(),beginWord);
        int n = wordList.size();
        vector<vector<int>> adList(n);
        int endWordInList=-1;
        for(int i=0;i<n;i++){
            string word = wordList[i];
            for(int j=i;j<n;j++){
                
                int diffCount=0;
                for(int k=0; k<word.size();k++){
                    if(wordList[j][k]!=word[k])diffCount++;
                }
                if(diffCount==1){   
                    adList[i].push_back(j);
                    adList[j].push_back(i);
                }
            }
            if(word==endWord){
                endWordInList=i;
            }
        }
        if(endWordInList==-1)return 0;

        // 0 -> endWordInList

        queue<pair<int,int>> q;
        q.push({0,1});
        vector<int> visited(n,0);
        int depth = 0;
        while(!q.empty()){
            int node = q.front().first;
            int currdepth = q.front().second;
            q.pop();
            
            // cout<<wordList[node]<< " depth:"<<currdepth<<endl;
            if(node == endWordInList){
                return currdepth;
            }
            for(auto next : adList[node]){
                if(visited[next]!=1){
                    q.push({next,currdepth+1});
                    visited[next]=1;
                }
            }
        }

        return depth;
    }
};