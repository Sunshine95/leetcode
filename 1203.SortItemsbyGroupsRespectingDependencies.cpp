class Solution
{
public:
    vector<int> visited;

    bool dfs(int i, vector<int> &order, vector<vector<int>> &edgeList)
    {

        if (visited[i] == 1)
            return true;

        else if (visited[i] == 2)
            return false;

        bool hasCycle;
        visited[i] = 1;

        for (int j = 0; j < edgeList[i].size(); j++)
        {
            if ((hasCycle = dfs(edgeList[i][j], order, edgeList)))
            {
                return true;
            }
        }

        order.push_back(i);
        visited[i] = 2;
        return false;
    }

    vector<int> topologicalSort(vector<vector<int>> &edgeList, vector<int> &vertexList)
    {

        vector<int> order;
        bool hasCycle = false;
        for (int i : vertexList)
        {
            if ((hasCycle = dfs(i, order, edgeList)))
            {
                cout << "flag";
                return vector<int>{};
            }
        }

        return order;
    }

    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {

        vector<vector<int>> groupItem(m);
        for (int i = 0; i < n; i++)
        {
            if (group[i] == -1)
            {
                group[i] = m++;
                groupItem.push_back(vector<int>{i});
            }
            else
            {
                groupItem[group[i]].push_back(i);
            }
        }

        vector<vector<int>> groupEdge(m);
        vector<int> groupVertex;

        int u, v;
        for (int i = 0; i < n; i++)
        {
            u = group[i];
            for (int j = 0; j < beforeItems[i].size(); j++)
            {
                v = group[beforeItems[i][j]];
                if (u != v)
                {
                    groupEdge[u].push_back(v);
                }
            }
        }

        vector<int> t;
        for (int i = 0; i < m; i++)
        {
            t.push_back(i);
        }

        visited.resize(m, 0);
        vector<int> groupOrder = topologicalSort(groupEdge, t);
        if (groupOrder.empty())
        {
            return groupOrder;
        }

        visited.clear();
        visited.resize(n, 0);
        vector<int> itemOrder;
        for (int i = 0; i < m; i++)
        {
            if (groupItem[groupOrder[i]].empty())
                continue;
            vector<int> temp = topologicalSort(beforeItems, groupItem[groupOrder[i]]);
            if (temp.empty())
            {
                return temp;
            }
            itemOrder.insert(itemOrder.end(), temp.begin(), temp.end());
        }

        return itemOrder;
    }
};