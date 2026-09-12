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
    vector<TreeNode*>in;
    void inorder(TreeNode* root){
        if(root==nullptr)
        return;
        inorder(root->left);
        in.push_back(root);
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        vector<int>copy;
        inorder(root);
        for(TreeNode* node:in){
            copy.push_back(node->val);
        }
        sort(begin(copy),end(copy));
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        for(int i=0;i<in.size();i++){
            if(in[i]->val!=copy[i]){
                if(first == nullptr)
                first = in[i];
                else
                second = in[i];
            }
        }
        swap(first->val,second->val);
        
    }
};