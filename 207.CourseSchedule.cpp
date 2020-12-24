class Solution
{
public:
    vector<int> visited;
    vector<vector<int>> adj;

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
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        adj.resize(numCourses);
        visited.resize(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (hasCycle(i))
            {
                return false;
            }
        }

        return true;
    }
};