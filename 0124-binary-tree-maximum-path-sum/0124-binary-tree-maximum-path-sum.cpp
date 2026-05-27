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
    int maxi = INT_MIN;
    int DFS(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        //max contibution from left side
        int left = max(0,DFS(root->left));
        //max contribution from right side
        int right = max(0,DFS(root->right));
        int curPath = left + right + root->val;
        maxi = max(maxi,curPath);
        return root->val + max(left,right);//best single path
    }
    int maxPathSum(TreeNode* root) {
        DFS(root);
        return maxi;
    }
};