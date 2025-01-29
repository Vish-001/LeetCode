

class Solution {
public:
    void Build(TreeNode* root, map<TreeNode*, TreeNode*>& mp) {
        if (root == nullptr) return;
        if (root->left) {
            mp[root->left] = root;
            Build(root->left, mp);
        }
        if (root->right) {
            mp[root->right] = root;
            Build(root->right, mp);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) {
            return {target->val};
        }

        map<TreeNode*, TreeNode*> mp;
        Build(root, mp);

        vector<int> ans;
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        q.push(target);  // Fixed: Added semicolon
        vis.insert(target);
        int lvl = 0;

        while (!q.empty()) {
            int n = q.size();
            bool isTargetLevel = (lvl == k);

            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (isTargetLevel) {
                    ans.push_back(node->val);
                    continue;
                }

                // Check left child
                if (node->left && vis.find(node->left) == vis.end()) {  // Fixed: vis.end -> vis.end()
                    vis.insert(node->left);
                    q.push(node->left);
                }

                // Check right child
                if (node->right && vis.find(node->right) == vis.end()) {  // Fixed: vis.end -> vis.end()
                    vis.insert(node->right);
                    q.push(node->right);
                }

                // Check parent
                if (mp.find(node) != mp.end()) {  // Fixed: mp.found -> mp.find()
                    TreeNode* parent = mp[node];
                    if (vis.find(parent) == vis.end()) {
                        vis.insert(parent);
                        q.push(parent);
                    }
                }
            }

            if (isTargetLevel) break;
            lvl++;  // Critical fix: Increment level after processing each level
        }

        return ans;
    }
};