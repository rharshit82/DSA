/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> arr;
        preOrder(root,arr);
        return arr;
    }
    void preOrder(Node* root, vector<int>&arr){
        if(!root) return;
        arr.push_back(root->val);
        for(int i=0;i<root->children.size();i++){
            preOrder(root->children[i],arr);
        }
    }
};