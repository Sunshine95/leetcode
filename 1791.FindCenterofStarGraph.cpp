class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {

        unordered_set<int> vertices;

        for (int i = 0; i < 2; i++)
        {
            if (vertices.find(edges[i][0]) != vertices.end())
            {
                return edges[i][0];
            }
            else
            {
                vertices.insert(edges[i][0]);
            }
            if (vertices.find(edges[i][1]) != vertices.end())
            {
                return edges[i][1];
            }
            else
            {
                vertices.insert(edges[i][1]);
            }
        }

        return -1;
    }
};