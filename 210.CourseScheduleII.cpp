class Solution
{
public:
    vector<int> visited;
    vector<vector<int>> adj;
    vector<int> order;

    bool hasCycle(int i)
    {

        if (visited[i] == 2)
        {
            return false;
        }
        else if (visited[i] == 1)
        {
            return true;
        }

        visited[i] = 1;

        for (int j = 0; j < adj[i].size(); j++)
        {
            if (hasCycle(adj[i][j]))
            {
                return true;
            }
        }

        visited[i] = 2;
        order.push_back(i);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {

        visited.resize(numCourses, 0);
        adj.resize(numCourses);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (hasCycle(i))
            {
                return vector<int>{};
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};