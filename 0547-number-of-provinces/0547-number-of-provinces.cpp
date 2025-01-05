class Solution {
public:
   void BFS(int node, vector<int>& vis, vector<vector<int>>& iC) {
    queue<int> q;
    q.push(node);
    vis[node] = 1; // Mark the node as visited
    while (!q.empty()) {
        int src = q.front();
        q.pop();
        for (int i = 0; i < iC.size(); i++) {
            if (iC[src][i] == 1 && vis[i] == 0) { // 0-based indexing
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& iC) {
    int ans = 0;
    int n = iC.size();
    vector<int> vis(n, 0); // Use size 'n' for 0-based indexing
    for (int i = 0; i < n; i++) { // 0-based indexing
        if (vis[i] == 0) {
            BFS(i, vis, iC);
            ans++;
        }
    }
    return ans;
}

};