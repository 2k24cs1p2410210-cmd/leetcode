class Solution {
public:

    TreeNode* buildingtree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.empty() || inorder.empty())
            return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        int pos = 0;

        while(inorder[pos] != preorder[0]) {
            pos++;
        }

        int left_size = pos;

        vector<int> leftpre;
        for(int i = 1; i <= left_size; i++) {
            leftpre.push_back(preorder[i]);
        }

        vector<int> rightpre;
        for(int i = left_size + 1; i < preorder.size(); i++) {
            rightpre.push_back(preorder[i]);
        }

        vector<int> leftin;
        for(int i = 0; i < pos; i++) {
            leftin.push_back(inorder[i]);
        }

        vector<int> rightin;
        for(int i = pos + 1; i < inorder.size(); i++) {
            rightin.push_back(inorder[i]);
        }

        root->left = buildingtree(leftpre, leftin);
        root->right = buildingtree(rightpre, rightin);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildingtree(preorder, inorder);
    }
};