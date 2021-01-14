class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, vector<int> &visited, int v)
    {

        if (visited[v])
            return;

        visited[v] = 1;
        for (int w = 0; w < isConnected.size(); w++)
        {
            if (isConnected[v][w])
            {
                dfs(isConnected, visited, w);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int n = isConnected.size();
        int setCount = 0;
        vector<int> visited(n, 0);

        for (int v = 0; v < isConnected.size(); v++)
        {
            if (!visited[v])
            {
                dfs(isConnected, visited, v);
                setCount++;
            }
        }

        return setCount;
    }
};