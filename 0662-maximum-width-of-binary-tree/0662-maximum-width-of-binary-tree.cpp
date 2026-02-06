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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        int maxWidth = INT_MIN;
        while(!q.empty()){
            unsigned long long strtIdx = q.front().second;
            unsigned long long endIdx = q.back().second;
            maxWidth = max(maxWidth,int(endIdx-strtIdx + 1));
            int s = q.size();
            for(int i=0;i<s;i++){
                auto curr = q.front();
                q.pop();
                if(curr.first->left){
                    q.push({curr.first->left, 2*curr.second+1});
                }
                if(curr.first->right){
                    q.push({curr.first->right,2* curr.second+2});
                }
            }
        }
        return maxWidth;
    }
};