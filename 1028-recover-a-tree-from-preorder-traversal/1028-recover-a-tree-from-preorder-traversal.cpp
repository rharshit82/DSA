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
    TreeNode* findRes(string &s, int &i, int d){
        int j = s.find_first_of("0123456789", i);
        if(j - i != d) return NULL;
        i = s.find("-", j);
        int no = stoi(s.substr(j, i-j));
        TreeNode* res = new TreeNode(no);
        res->left = findRes(s,i,d+1);
        res->right = findRes(s,i,d+1);
        return res;
    }
    TreeNode* recoverFromPreorder(string s) {
        int i =0;
        return findRes(s,i, 0);
    }
};