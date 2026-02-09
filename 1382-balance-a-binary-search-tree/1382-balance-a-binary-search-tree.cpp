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
    void inorder(TreeNode* root,vector<int>& arr){
        if(root == NULL){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* buildBST(vector<int>& arr,int s,int e){
        if(s > e){
            return NULL;
        }
        int mid = (s + e)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildBST(arr,s,mid - 1);
        root->right = buildBST(arr,mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        return buildBST(arr,0,arr.size()-1);
    }
};