struct Node{
    Node* child[26];
    bool isEnd;
    Node() { 
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;  
        }
    }
    bool containsChar(char c){
        return child[c-'a']!=NULL;
    }
    void insertChar(char c, Node* node){
        child[c-'a'] = node;
    }
    Node* getChild(char c){
        return child[c-'a'];
    }
    void setEnd(){
        isEnd=true;
    }
    bool isWordEnd(){
        return isEnd;
    }
};
class Trie {
    Node* root;
public:
    Trie(){root = new Node;}
    void insertWord(string word){
        Node* node =root;
        for(int i=0;i<word.size();i++){
            if(!node->containsChar(word[i])){
                node->insertChar(word[i], new Node());
            }
            node = node->getChild(word[i]);
        }
        node->setEnd();
    }
    bool startsWith(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsChar(word[i])){
                return false;
            }
            node = node->getChild(word[i]);
        }
        return true;
    }
    bool searchWord(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsChar(word[i])){
                return false;
            }
            node = node->getChild(word[i]);
        }
        return node->isWordEnd();
    }
};
class Solution {
private:
    unordered_set<string> ans;
    Trie* trie;
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& visited, string word, int i, int j){
        int n=board.size(), m = board[0].size();
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j]==1){
            return false;
        } 
        word.push_back(board[i][j]);
        if(!trie->startsWith(word)){
            return false;
        }
        if(trie->searchWord(word)){
            ans.insert(word);
        }
        visited[i][j]=1;
        bool ans =  
        dfs(board,visited,word,i+1,j)|| 
        dfs(board,visited,word,i-1,j)|| 
        dfs(board,visited,word,i,j+1)|| 
        dfs(board,visited,word,i,j-1); 
        visited[i][j]=0;
        word.pop_back();
        return ans;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size(), m = board[0].size();
        trie = new Trie();
        for(auto word:words){
            trie->insertWord(word);
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                string word="";
                vector<vector<int>> visited(n,vector<int>(m,0));
                dfs(board, visited, word, j, k);
            }
        }
        vector<string> result(ans.begin(),ans.end());
        return result;
    }
};