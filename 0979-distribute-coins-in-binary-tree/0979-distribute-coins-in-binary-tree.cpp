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
    int moves  = 0;
    int dfs(TreeNode* root){
        if(root==nullptr)
        return 0;
        int lb = dfs(root->left);
        int rb = dfs(root->right);
        moves+=abs(lb)+abs(rb);
        return root->val+lb+rb-1;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};