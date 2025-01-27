class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        // Map to group nodes by horizontal position and level
        map<int, map<int, multiset<int>>> nodes; // {posn -> {level -> {node_values}}}

        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {posn, level}}
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int posn = p.second.first;
            int lvl = p.second.second;

            // Add the current node's value to the map
            nodes[posn][lvl].insert(node->val);

            // Add left and right children with updated horizontal positions and levels
            if (node->left) {
                q.push({node->left, {posn - 1, lvl + 1}});
            }
            if (node->right) {
                q.push({node->right, {posn + 1, lvl + 1}});
            }
        }

        // Construct the result
        for (auto& [posn, levels] : nodes) {
            vector<int> column;
            for (auto& [lvl, values] : levels) {
                column.insert(column.end(), values.begin(), values.end());
            }
            ans.push_back(column);
        }

        return ans;
    }
};
