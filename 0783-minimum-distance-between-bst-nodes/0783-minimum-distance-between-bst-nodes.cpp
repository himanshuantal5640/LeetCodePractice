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
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        int prev = -1;
        int ans = INT_MAX;
        while(cur != NULL || !st.empty()){
            while(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if(prev != -1){
                ans = min(ans,cur->val - prev);
            }
            prev = cur->val;
            cur = cur->right;
        }
        return ans;
    }
};