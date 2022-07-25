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
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;
        unsigned long long res=0;
        q.push({root,0});
        while(!q.empty()){
            int sz = q.size();
            unsigned long long mmin = q.front().second;
            unsigned long long left, right;
            for(int i=0; i<sz; i++){
                TreeNode* curr = q.front().first;
                unsigned long long vl = q.front().second - mmin;
                q.pop();
                if(i==0) left = vl;
                if(i==sz-1) right = vl;
                if(curr->left){
                    q.push({curr->left,2*vl+1});
                }
                if(curr->right){
                    q.push({curr->right,2*vl+2});
                }
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};