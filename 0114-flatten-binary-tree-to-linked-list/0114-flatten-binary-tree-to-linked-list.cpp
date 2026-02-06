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
    // we cannot directly build LinkedList using preorder so we use reverse preorder
    // we have to make global nextRight so that on every recursive we keep a track of nextRight
public:

    TreeNode* nextRight = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};