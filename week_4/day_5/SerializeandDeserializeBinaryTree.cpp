class Codec {
public:

    void helper(TreeNode* root, string &ans) {

        if (root == NULL) {
            ans += "N,";
            return;
        }

        ans += to_string(root->val) + ",";

        helper(root->left, ans);
        helper(root->right, ans);
    }

    string serialize(TreeNode* root) {

        string ans = "";
        helper(root, ans);
        return ans;
    }

    TreeNode* build(vector<string> &nodes, int &index) {

        if (nodes[index] == "N") {
            index++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index]));
        index++;

        root->left = build(nodes, index);
        root->right = build(nodes, index);

        return root;
    }

    TreeNode* deserialize(string data) {

        vector<string> nodes;
        string temp = "";

        for (char ch : data) {

            if (ch == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }

        int index = 0;
        return build(nodes, index);
    }
};
