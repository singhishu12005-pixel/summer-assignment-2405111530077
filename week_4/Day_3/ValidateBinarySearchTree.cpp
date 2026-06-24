class Solution {
public:
    bool isValid(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
        if (root == NULL) {
            return true;
        }

        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }

        return isValid(root->left, minVal, root->val) &&
               isValid(root->right, root->val, maxVal);
    }
};   
