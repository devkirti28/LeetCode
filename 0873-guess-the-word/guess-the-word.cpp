/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    private:
    int findDistance(string a, string b){
        int count=0;
        for(int i=0;i<6;i++){
            if(a[i]==b[i])count++;
        }
        return count;
    }
    int findCandidate(set<int> candidates,vector<vector<int>>& adlist){
        int word=0, minsize=adlist.size();
        int n = adlist.size();
        for(auto i : candidates){
            vector<int> freq(7,0);
            int maxFreq=0;
            for(int j=0;j<n;j++){
                if(candidates.find(j)==candidates.end())continue;
                freq[adlist[i][j]]++;
                maxFreq= max(freq[adlist[i][j]],maxFreq);
            }
            if(maxFreq<minsize){
                minsize= maxFreq;
                word = i;
            }
        }
        return word;
    }
public:
    void findSecretWord(vector<string>& words, Master& master) {
        int n = words.size();
        vector<vector<int>> adlist(n,vector<int> (n));
        set<int> candidates;
        for(int i=0;i<n;i++){
            candidates.insert(i);
            for(int j=i+1;j<n;j++){
                int distance = findDistance(words[i],words[j]);
                adlist[i][j]=distance;
                adlist[j][i]=distance;
            }
        }
        
        
        while(true){
            int it = findCandidate(candidates,adlist);
            string word = words[it];
            int distance = master.guess(word);
            cout<<it<< word<<distance<<  endl;
            if(distance == 6){
                break;
            }
            set<int> newCandidates;
            for(int i=0;i<n;i++){
                if(it!=i && adlist[it][i]==distance && candidates.find(i)!=candidates.end()){
                    cout<<i<<endl;
                    newCandidates.insert(i);
                }
            }
            cout<<candidates.size()<< endl;
            candidates = newCandidates;
        }

    }
};