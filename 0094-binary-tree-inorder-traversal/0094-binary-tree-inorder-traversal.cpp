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
    // void inorder(vector<int>& ino,TreeNode* root){
    //     if(root == NULL){
    //         return;
    //     }
    //     inorder(ino,root->left);
    //     ino.push_back(root->val);
    //     inorder(ino,root->right);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ino;
        // inorder(ino,root);
        // return ino;
        vector<int> ino;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()==true){
                    break;
                }
                node = st.top();
                st.pop();
                ino.push_back(node->val);
                node = node->right;
            }
        }
        return ino;
    }
};