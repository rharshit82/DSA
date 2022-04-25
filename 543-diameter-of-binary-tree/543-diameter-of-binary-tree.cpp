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
    int findres(TreeNode* root, int &d) {
        if(!root) return 0;
        int ld = findres(root->left,d);
        int rd = findres(root->right,d);
        d = max(d,ld+rd);
        return 1+ max(ld,rd);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int d = 0;
        findres(root,d);
        return d;
    }
};