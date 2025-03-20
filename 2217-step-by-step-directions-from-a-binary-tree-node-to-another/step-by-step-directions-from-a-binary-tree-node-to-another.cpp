/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfsForParent(TreeNode* node, TreeNode* parent, unordered_map<int,TreeNode*>& parentMap){
        if(node==nullptr)return;
        parentMap[node->val] = parent;
        dfsForParent(node->left, node, parentMap);
        dfsForParent(node->right, node, parentMap);
    }
    TreeNode* findStartNode(TreeNode* node, int target){
        if(node==nullptr)return nullptr;
        if(node->val == target) return node;
        TreeNode* leftTree = findStartNode(node->left, target);
        TreeNode* rightTree = findStartNode(node->right, target);
        if(leftTree != nullptr)return leftTree;
        if(rightTree != nullptr)return rightTree;
        return nullptr;
    }

    bool findNode(TreeNode* node, int target, string& path){
        if(node==nullptr)return false;
        if(node->val == target) return true;

        path.push_back('L');
        if(findNode(node->left, target, path))return true;
        path.pop_back();
        path.push_back('R');
        if(findNode(node->right, target, path))return true;
        path.pop_back();
        return false;
    }

    bool dfs(TreeNode* node, int target, string& path, unordered_map<int,bool> vis, unordered_map<int,TreeNode*>& parent){
        if(node==nullptr || vis[node->val])return false;
        vis[node->val] = true;
        if(node->val == target)return true;

        path.push_back('L');
        if(dfs(node->left, target, path, vis, parent))return true;
        path.pop_back();

        path.push_back('R');
        if(dfs(node->right, target, path, vis, parent))return true;
        path.pop_back();

        path.push_back('U');
        if(dfs(parent[node->val], target, path, vis, parent))return true;
        path.pop_back();

        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        //1. need to track parent pointers
            // unordered_map<int,TreeNode*> parent;
            // dfsForParent(root, nullptr, parent);
        //2. find start Node
            // TreeNode* startNode = findStartNode(root,startValue); 
        //3. dfs from start to end with a visitied while maintaining a string for storing the path
        //  a. dfs(node, targetVal, string path, visited)

        
        // int val = startNode->val;
        // cout<<val<<endl;
        // unordered_map<int,bool> visited;
        // string ans="";
        // dfs(startNode, destValue, ans, visited, parent);
        
        // return ans;

        string pathStart;
        findNode(root, startValue, pathStart);

        string pathDest;
        findNode(root, destValue, pathDest);

        int ind=0;

        while(ind < pathStart.size() && ind < pathDest.size()){
            if(pathStart[ind]==pathDest[ind]){
                ind++;
                continue;
            }else{
                break;
            }
        }
        string ans="";
        int up=ind;
        while(up<pathStart.size()){
            ans+='U';
            up++;
        }

        while(ind<pathDest.size()){
            ans+=pathDest[ind++];
        }
        return ans;
    }
};