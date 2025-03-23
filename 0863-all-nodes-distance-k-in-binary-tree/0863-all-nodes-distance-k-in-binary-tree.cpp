class Solution {
public:
    void Build(TreeNode* node, TreeNode* parent, map<TreeNode*, TreeNode*>& mp) {
        if (node == nullptr) return;
        mp[node] = parent;
        Build(node->left, node, mp);
        Build(node->right, node, mp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == nullptr) {
            return {};
        }

        vector<int> ans;
        map<TreeNode*, TreeNode*> mp; // Parent mapping
        Build(root, nullptr, mp);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;
        q.push(target);
        vis.insert(target);
        int lvl = 0;

        while (!q.empty()) {
            int n = q.size();
            if (lvl == k) {
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();

                // Visit left child
                if (node->left && vis.find(node->left) == vis.end()) {
                    vis.insert(node->left);
                    q.push(node->left);
                }

                // Visit right child
                if (node->right && vis.find(node->right) == vis.end()) {
                    vis.insert(node->right);
                    q.push(node->right);
                }

                // Visit parent
                TreeNode* parent = mp[node];
                if (parent && vis.find(parent) == vis.end()) {
                    vis.insert(parent);
                    q.push(parent);
                }
            }
            lvl++;
        }

        return ans;
    }
};
