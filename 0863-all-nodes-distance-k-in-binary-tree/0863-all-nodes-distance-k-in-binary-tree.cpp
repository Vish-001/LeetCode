

class Solution {
public:
    void Build(TreeNode* root, map<TreeNode*, TreeNode*>& mp) 
    {
        if (root == nullptr) return;
        if (root->left) 
        {
            mp[root->left] = root;
            Build(root->left, mp);
        }
        if (root->right) 
        {
            mp[root->right] = root;
            Build(root->right, mp);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        if (k == 0) 
        {
            return {target->val};
        }

        map<TreeNode*, TreeNode*> mp;
        Build(root, mp);

        vector<int> ans;
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        q.push(target);  
        vis.insert(target);
        int lvl = 0;

        while (!q.empty()) 
        {
            int n = q.size();
            

            for (int i = 0; i < n; ++i) 
            {
                TreeNode* node = q.front();
                q.pop();

                if (lvl==k) 
                {
                    ans.push_back(node->val);
                    continue;
                }

                if (node->left && vis.find(node->left) == vis.end()) 
                {  
                    vis.insert(node->left);
                    q.push(node->left);
                }

                if (node->right && vis.find(node->right) == vis.end()) 
                {  
                    vis.insert(node->right);
                    q.push(node->right);
                }

                if (mp.find(node) != mp.end()) 
                { 
                    TreeNode* parent = mp[node];
                    if (vis.find(parent) == vis.end()) 
                    {
                        vis.insert(parent);
                        q.push(parent);
                    }
                }
            }

            if (lvl==k) break;
            lvl++;  
        }

        return ans;
    }
};