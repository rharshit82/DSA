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
    
    bool isEqual(TreeNode* Node, TreeNode* subRoot){
        if(!Node and !subRoot) return true;
        if(!Node or !subRoot) return false;
        if(Node->val!=subRoot->val) return false;
        return isEqual(Node->left, subRoot->left) and isEqual(Node->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(isEqual(root,subRoot)) return true;
        return isSubtree(root->left, subRoot) or isSubtree(root->right,subRoot);
    }
    
};