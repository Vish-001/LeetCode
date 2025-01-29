/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if (!root) return "#";  // Handling empty tree

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) 
        {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) 
            {
                ans += "#,";
            } 
            else 
            {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if (data == "#") return nullptr; // Handling empty tree

        stringstream ss(data);
        string str;
        getline(ss, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) 
        {
            TreeNode* node = q.front();
            q.pop();

            if (getline(ss, str, ',')) 
            {
                if (str != "#") 
                {
                    node->left = new TreeNode(stoi(str));
                    q.push(node->left);
                }
            }
            if (getline(ss, str, ',')) 
            {
                if (str != "#") 
                {
                    node->right = new TreeNode(stoi(str));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};
