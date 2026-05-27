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
    int DFS(TreeNode* root,int maxi){
        if(root == NULL){
            return 0;
        }
        int cnt = 0;
        if(root->val >= maxi){
            cnt++;
        }
        maxi = max(maxi,root->val);
        cnt += DFS(root->left,maxi);//left tree
        cnt += DFS(root->right,maxi);//right tree
        return cnt;
    }
    int goodNodes(TreeNode* root) {
        return DFS(root,root->val);
    }
};