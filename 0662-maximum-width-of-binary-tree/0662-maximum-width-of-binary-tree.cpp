class Solution 
{
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root) return 0;
        long long ans=0;

        queue<pair<TreeNode*,int>>todo;
        todo.push({root,0});

        while(!todo.empty())
        {
            int k=todo.size();
            long long mini=todo.front().second;
            long long last,first;

            for(int i=0;i<k;i++)
            {
                auto p=todo.front();
                todo.pop();
                long long curr=p.second-mini;
                TreeNode*Node=p.first;

                if(i==0) first=curr;
                if(i==k-1) last=curr;
                
                if(Node->left)
                {
                    todo.push({Node->left,2*curr+1});
                }
                if(Node->right)
                {
                    todo.push({Node->right,2*curr+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};