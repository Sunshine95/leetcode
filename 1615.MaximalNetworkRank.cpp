class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {

        vector<int> degree(n);
        vector<unordered_set<int>> adj(n);
        vector<unordered_set<int>> degSets(n);

        for (int i = 0; i < roads.size(); i++)
        {
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;

            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]);
        }

        for (int i = 0; i < n; i++)
        {
            degSets[degree[i]].insert(i);
        }

        int maxRank = INT_MIN;
        int k = 2;
        int i = n - 1;

        while (i >= 0 && k)
        {

            if (!degSets[i].empty())
            {
                int j;
                if (k == 2)
                    j = i;

                for (int u : degSets[i])
                {
                    for (int v : degSets[j])
                    {
                        if (v == u)
                            continue;
                        int isConnected = (adj[u].find(v) != adj[u].end()) ? 1 : 0;
                        int rank = degree[u] + degree[v] - isConnected;
                        maxRank = max(rank, maxRank);
                    }
                }
                k--;
            }
            i--;
        }

        return maxRank;
    }
};