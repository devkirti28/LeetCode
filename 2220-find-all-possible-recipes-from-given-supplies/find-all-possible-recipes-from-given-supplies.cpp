class Solution {
private:
    int recipeReady(set<string>& sup, vector<vector<string>>& ig, vector<string>& recipes, vector<bool>& recipeMade){
        int count=0;
        for(int i =0 ;i<ig.size(); i++){
            if(recipeMade[i]){
                count++;
                continue;
            }
            bool allPresent=true;
            for(int j=0; j<ig[i].size();j++){
                if(sup.find(ig[i][j])==sup.end()){
                    allPresent=false;
                    break;
                }
            }
            if(allPresent){
                count++;
                recipeMade[i]=true;
                sup.insert(recipes[i]);
            }
        }
        return count;
    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        set<string> sup(supplies.begin(),supplies.end());
        vector<bool> recipeMade(recipes.size(), false);
        int prevCount = 0;
        while(true){
            int count = recipeReady(sup, ingredients, recipes, recipeMade);
            if(prevCount==count)break;
            prevCount = count;
        }

        vector<string> ans;
        for(int i=0;i<recipes.size();i++){
            if(recipeMade[i]){
                ans.push_back(recipes[i]);
            }
        }
        return ans;
    }
};