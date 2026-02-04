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
            // reverse preorder traversal for right side and preorder for left side view..;
    void preorder(TreeNode* root,int level,vector<int>& res){
        if(root == nullptr){
            return;
        }
        if(res.size() == level){
            res.push_back(root->val);
        }
        preorder(root->right,level+1,res);
        preorder(root->left,level+1,res);
        // for left side just go left and right instead of right left in preorder...
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        preorder(root,0,res);
        return res;
    }
};