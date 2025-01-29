

class Solution {
public:
    void Build(TreeNode* root, map<TreeNode*, TreeNode*>& PM) 
    {
        if (root == nullptr) return;
        if (root->left) 
        {
            PM[root->left] = root;
            Build(root->left, PM);
        }
        if (root->right) 
        {
            PM[root->right] = root;
            Build(root->right, PM);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        map<TreeNode*, TreeNode*> PM;
        Build(root, PM);

        queue<pair<TreeNode*, int>> q;
        unordered_set<TreeNode*> visited;
        vector<int> ans;

        if (k == 0) 
        {
            ans.push_back(target->val);
            return ans;
        }

        q.push({target, 0});
        visited.insert(target);

        while (!q.empty()) 
        {
            int n = q.size();
            for (int i = 0; i < n; ++i) 
            {
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                int lvl = p.second;

                if (lvl == k) 
                {
                    ans.push_back(node->val);
                    continue;
                }

                if (node->left && visited.find(node->left) == visited.end()) 
                {
                    visited.insert(node->left);
                    q.push({node->left, lvl + 1});
                }
                if (node->right && visited.find(node->right) == visited.end()) 
                {
                    visited.insert(node->right);
                    q.push({node->right, lvl + 1});
                }
                if (PM.find(node) != PM.end()) 
                {
                    TreeNode* parent = PM[node];
                    if (visited.find(parent) == visited.end()) 
                    {
                        visited.insert(parent);
                        q.push({parent, lvl + 1});
                    }
                }
            }
        }

        return ans;
    }
};