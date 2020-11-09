class Solution
{
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> inDeg;
    unordered_map<int, bool> visited;

    void dfs(int v, vector<int> &array)
    {

        visited[v] = true;
        array.push_back(v);

        for (int u : adj[v])
        {
            if (!visited[u])
                dfs(u, array);
        }

        return;
    }

    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {

        vector<int> array;

        for (int i = 0; i < adjacentPairs.size(); i++)
        {

            inDeg[adjacentPairs[i][0]]++;
            inDeg[adjacentPairs[i][1]]++;

            adj[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            adj[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);

            visited[adjacentPairs[i][0]] = false;
            visited[adjacentPairs[i][1]] = false;
        }

        for (auto v : inDeg)
        {
            if (v.second == 1)
            {
                if (!visited[v.first])
                {
                    dfs(v.first, array);
                }
            }
        }

        return array;
    }
};