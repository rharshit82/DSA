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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
    
        while(true){
           if(root!=NULL){
               st.push(root);
               root=root->left;
           } else{
               if(st.empty()) break;
               TreeNode* curr= st.top();
               res.push_back(curr->val);
               st.pop();
               root=curr->right;
           }
            
        }
        return res;
    }
};