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
    void findDiff(TreeNode* root, int &res, int &minsofar){
        if(!root) return;
        findDiff(root->left,res,minsofar);
        res = min(res, abs(minsofar - root->val));
        minsofar = min(minsofar, root->val);
        findDiff(root->right,res,minsofar);
    }
    void findDiff2(TreeNode* root, int &res, int &minsofar){
        if(!root) return;
        findDiff2(root->right,res,minsofar);
        res = min(res, abs(minsofar - root->val));
        minsofar = min(minsofar, root->val);
        findDiff2(root->left,res,minsofar);
    }
    int getMinimumDifference(TreeNode* root) {
        if(!root) return INT_MAX;
        int minsofar = INT_MAX,minsofar2=INT_MAX;
        int res = INT_MAX,res2=INT_MAX;
        findDiff(root,res,minsofar);
        findDiff2(root,res2,minsofar2);
        return min(res,res2);
    }
};