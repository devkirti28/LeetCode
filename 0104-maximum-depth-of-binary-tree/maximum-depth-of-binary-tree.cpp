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
    vector<vector<int>> ans;
    int dfs(TreeNode* root) {
        if(root==nullptr) return 0;

        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        int h = max(leftHeight, rightHeight);
        if (h == ans.size()){
            ans.push_back({});
        }
        ans[h].push_back(root->val);
        return 1 + h;
    }
public:
    int maxDepth(TreeNode* root) {
        int h=dfs(root);
        for(int i=0;i<ans.size();i++){
            cout<<i<<endl;
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        return h;
    }
};