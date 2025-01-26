/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        queue<pair<TreeNode*,pair<int,int>>>todo;
        map<int,map<int,multiset<int>>>nodes;

        todo.push({root,{0,0}});

        while(!todo.empty())
        {
            auto p=todo.front();
            todo.pop();

            TreeNode*node=p.first;
            int x=p.second.first;
            int y=p.second.second;

            nodes[x][y].insert(node->val);

            if(node->left)
            {
                todo.push({node->left,{x-1,y+1}});
            }
            if(node->right)
            {
                todo.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>ans;
        for (auto verticalLevel : nodes)
        {
            vector<int> column;
            for (auto horizontalLevel : verticalLevel.second)
            {
                column.insert(column.end(), horizontalLevel.second.begin(),
                 horizontalLevel.second.end());
            }
            ans.push_back(column);
        }
        return ans;
    }
};