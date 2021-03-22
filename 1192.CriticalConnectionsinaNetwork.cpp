class Solution
{
public:
    // tarjan's algorithm

    vector<vector<int>> adj;

    int id = 0;
    int comp_count = 0;

    stack<int> s;
    vector<int> ids;
    vector<int> low;
    vector<bool> onStack;

    void dfs(int u, int prev)
    {

        s.push(u);
        onStack[u] = true;
        ids[u] = low[u] = id;
        id++;

        for (int v : adj[u])
        {

            if (v == prev)
            {
                continue;
            }

            if (ids[v] == -1)
            {
                dfs(v, u);
            }
            if (onStack[v])
            {
                low[u] = min(low[u], low[v]);
            }
        }

        if (ids[u] == low[u])
        {
            while (s.top() != u)
            {
                onStack[s.top()] = false;
                low[s.top()] = ids[u];
                s.pop();
            }
            onStack[u] = false;
            s.pop();
            comp_count++;
        }

        return;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {

        ids.resize(n, -1);
        low.resize(n);
        onStack.resize(n, false);

        adj.resize(n, vector<int>{});
        vector<vector<int>> out;

        for (vector<int> e : connections)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (ids[i] == -1)
            {
                dfs(i, -1);
            }
        }

        for (vector<int> e : connections)
        {
            if (low[e[0]] != low[e[1]])
            {
                out.push_back(vector<int>{e[0], e[1]});
            }
        }

        return out;
    }
};