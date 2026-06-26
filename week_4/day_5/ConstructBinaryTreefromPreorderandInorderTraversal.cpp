class Solution {
public:
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right) {

        if (left > right)
            return NULL;

        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int index = mp[rootValue];

        root->left = build(preorder, inorder, left, index - 1);
        root->right = build(preorder, inorder, index + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};
