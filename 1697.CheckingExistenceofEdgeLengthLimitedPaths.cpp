class Solution
{
public:
    vector<int> parent;

    int find(int x)
    {
        if (parent[x] == -1)
            return x;
        else
        {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    void uni(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);

        if (xset != yset)
        {
            parent[yset] = xset;
        }

        return;
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {

        parent.resize(n, -1);

        for (int i = 0; i < queries.size(); i++)
        {
            queries[i].push_back(i);
        }

        sort(edgeList.begin(), edgeList.end(), [](vector<int> &a, vector<int> &b) { return a.back() < b.back(); });
        sort(queries.begin(), queries.end(), [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });

        vector<bool> output(queries.size());

        int j = 0;
        for (int i = 0; i < queries.size(); i++)
        {

            while (j < edgeList.size() && edgeList[j].back() < queries[i][2])
            {
                uni(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            output[queries[i].back()] = (find(queries[i][0]) == find(queries[i][1]));
        }

        return output;
    }
};