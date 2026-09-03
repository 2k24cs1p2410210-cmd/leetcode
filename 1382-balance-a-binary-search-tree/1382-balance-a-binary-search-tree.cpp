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
    vector<int>arr;
    void inorder(TreeNode* root){
        if(root==nullptr)
        return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* buildbst(vector<int>&arr,int left ,int right){
        if(left>right)
        return nullptr;
        int mid = left+(right-left)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildbst(arr,left,mid-1);
        root->right = buildbst(arr,mid+1,right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return buildbst(arr,0,arr.size()-1);
        
    }
};