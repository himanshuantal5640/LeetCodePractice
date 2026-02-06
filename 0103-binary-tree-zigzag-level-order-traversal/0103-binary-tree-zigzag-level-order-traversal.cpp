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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == NULL){
            return ans;
        }
        q.push(root);
        bool LTR = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> le(n);
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                int idx = LTR ? i : n - i - 1;
                le[idx] = node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(le);
            LTR = !LTR;
        }
        return ans;
    }
};