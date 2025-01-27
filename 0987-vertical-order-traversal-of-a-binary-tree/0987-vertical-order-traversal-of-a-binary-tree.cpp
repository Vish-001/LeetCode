class Solution 
{
    public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        // Queue stores the node and its coordinates (x, y)
        queue<pair<TreeNode*, pair<int, int>>> q;

        // Map stores nodes based on x-coordinate, then y-coordinate, then sorted values
        map<int, map<int, multiset<int>>> mp;

        // Push root with its position
        q.push({root, {0, 0}});

        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                auto P = q.front();
                q.pop();
                TreeNode* node = P.first;
                int x = P.second.first;  // x-coordinate (vertical position)
                int y = P.second.second;  // y-coordinate (horizontal position)
                
                // Insert node's value into the map
                mp[y][x].insert(node->val);

                // Traverse left and right children
                if(node->left)
                {
                    q.push({node->left, {x + 1, y - 1}});
                }
                if(node->right)
                {
                    q.push({node->right, {x + 1, y + 1}});
                }
            }
        }

        // Construct the answer from the map
        for(auto& p : mp) 
        {
            vector<int> column;
            for(auto& q : p.second) 
            {
                column.insert(column.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(column);
        }

        return ans;
    }
};
