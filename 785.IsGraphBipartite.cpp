class Solution
{
public:
    // colour graph twice

    bool isBipartite(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<int> colour(n, -1);
        queue<int> q;

        int i = 0;
        while (i < n)
        {

            colour[i] = 0;
            q.push(i);

            while (!q.empty())
            {

                int u = q.front();
                q.pop();

                for (int j = 0; j < graph[u].size(); j++)
                {

                    int v = graph[u][j];
                    if (colour[v] == -1)
                    {
                        q.push(v);
                        colour[v] = 1 - colour[u];
                    }
                    else
                    {
                        if (colour[v] == colour[u])
                        {
                            return false;
                        }
                    }
                }
            }

            while (i < n && colour[i] != -1)
                i++;
        }

        return true;
    }
};