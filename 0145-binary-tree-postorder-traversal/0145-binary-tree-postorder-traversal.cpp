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
    void postorder(vector<int> &post,TreeNode* root){
        if(root == nullptr){
            return;
        }
        postorder(post,root->left);
        postorder(post,root->right);
        post.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        postorder(post,root);
        return post;
    }
};