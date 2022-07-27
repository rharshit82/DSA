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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp = root;
        if(!root) return NULL;
        if(root->val == key) return helper(root);
        while(temp){
            if(temp->val > key){
                if(temp->left!=NULL and temp->left->val == key){
                    temp->left = helper(temp->left);
                    break;
                } else{
                    temp = temp->left;
                }
            } else{
                if(temp->right!=NULL and temp->right->val == key){
                    temp->right = helper(temp->right);
                    break;
                } else{
                    temp = temp->right;
                }
            }
        }
        return root;
    }
    
    TreeNode* helper(TreeNode* root){
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        TreeNode* right = root->right;
        TreeNode* lastRight= findLastRight(root->left);
        lastRight->right = right;
        return root->left;
    }
    TreeNode* findLastRight(TreeNode* root){
        if(!root) return NULL;
        while(root->right) root = root->right;
        return root;
    }
};