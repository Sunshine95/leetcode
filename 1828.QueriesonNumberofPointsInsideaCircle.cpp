class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {

        vector<int> out;

        for (int j = 0; j < queries.size(); j++)
        {

            int xc = queries[j][0];
            int yc = queries[j][1];
            double r = queries[j][2];

            out.push_back(0);
            for (int i = 0; i < points.size(); i++)
            {
                int xp = points[i][0];
                int yp = points[i][1];

                double d = pow((pow((xc - xp), 2) + pow((yc - yp), 2)), 0.5);
                if (d <= r)
                {
                    out[j]++;
                }
            }
        }

        return out;
    }
};