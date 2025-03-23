class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        map<int, map<int, multiset<int>>> nodes; // x -> (y -> {values})
        queue<pair<TreeNode*, pair<int, int>>> q; // (node, (x, y))

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            int x = pos.first, y = pos.second;

            nodes[x][y].insert(node->val);

            if (node->left) q.push({node->left, {x - 1, y + 1}});
            if (node->right) q.push({node->right, {x + 1, y + 1}});
        }

        for (auto& p : nodes) 
        {
            vector<int> col;
            for (auto& q : p.second) 
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
