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
    vector<int>ans;
    int dfs (TreeNode* node){
        if(node==nullptr)
        return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        if(left==-1 ||right==-1 ||left!=right)
        return -1;
        int size = left+right+1;
        ans.push_back(size);
        return size;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        sort(ans.begin(),ans.end(),greater<int>());
        if(ans.size()<k)
        return -1;
        return ans[k-1];
    }
};