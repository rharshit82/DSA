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

class NodeValue {
public:
    int maxNode, minNode, maxSum;
    
    NodeValue(int minNode, int maxNode, int maxSum) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSum = maxSum;
    }
};
class Solution {
public:
    int res=0;
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        if (left.maxNode < root->val && root->val < right.minNode) {
            res = max(res, left.maxSum + right.maxSum + root->val);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), 
                            left.maxSum + right.maxSum + root->val);
        }
        
        return NodeValue(INT_MIN, INT_MAX, 0);
    }
    int maxSumBST(TreeNode* root) {
         largestBSTSubtreeHelper(root);
        return res;
    }
};