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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int vertical = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            mp[vertical][level].insert(curr->val);
            if(curr->left){
                q.push({curr->left, {vertical-1, level+1}});
            }
            if(curr->right){
                q.push({curr->right, {vertical+1, level+1}});
            }
        }
        vector<vector<int>> res;
        for(auto p: mp){
            vector<int> col;
            for(auto q: p.second){
                for(auto ele: q.second){
                    col.push_back(ele);
                }
            }
            res.push_back(col);
        }
        return res;
    }
};