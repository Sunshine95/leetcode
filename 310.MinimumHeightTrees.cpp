class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {

        vector<int> out;

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        vector<bool> visited(n, false);
        queue<int> leaf;

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (degree[i] <= 1)
            {
                visited[i] = true;
                leaf.push(i);
            }
        }

        int count = leaf.size();
        while (!leaf.empty())
        {

            int temp = leaf.front();
            for (int j = 0; j < adj[temp].size(); j++)
            {
                if (visited[adj[temp][j]])
                    continue;

                if (--degree[adj[temp][j]] == 1)
                {
                    visited[adj[temp][j]] = true;
                    leaf.push(adj[temp][j]);
                }
            }

            leaf.pop();
            count--;
            out.push_back(temp);

            if (count == 0)
            {
                if (leaf.size())
                {
                    count = leaf.size();
                    out.clear();
                }
            }
        }

        return out;
    }
};