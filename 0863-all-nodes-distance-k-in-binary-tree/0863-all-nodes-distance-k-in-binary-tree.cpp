/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Helper function to build a parent-child map
    void Build(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (root == nullptr) return;
        parentMap[root] = parent;
        Build(root->left, root, parentMap);
        Build(root->right, root, parentMap);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap; // To store parent pointers
        Build(root, nullptr, parentMap);

        vector<int> result;
        unordered_set<TreeNode*> visited; // To avoid revisiting nodes
        queue<TreeNode*> q; // BFS queue

        q.push(target); // Start BFS from the target node
        visited.insert(target);

        int currentDistance = 0;

        while (!q.empty()) {
            if (currentDistance == k) {
                // Collect all nodes at distance k
                while (!q.empty()) {
                    TreeNode* node = q.front();
                    q.pop();
                    result.push_back(node->val);
                }
                break;
            }

            int levelSize = q.size(); // Number of nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Add left child to the queue if not visited
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                // Add right child to the queue if not visited
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                // Add parent to the queue if not visited
                if (parentMap[node] && visited.find(parentMap[node]) == visited.end()) {
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
            currentDistance++;
        }

        return result;
    }
};
