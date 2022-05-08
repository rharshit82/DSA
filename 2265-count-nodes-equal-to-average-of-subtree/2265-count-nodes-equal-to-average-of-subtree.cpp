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
    
    int res=0;
    pair<int,int> postOrder(TreeNode* root){
        if(!root) return {0,0};
        auto left= postOrder(root->left);
        auto right= postOrder(root->right);
        int sum = root->val + left.first+ right.first;
        int cnt = left.second+ right.second +1;
        if(sum/cnt==root->val) res++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        postOrder(root);
        return res;
    }
};