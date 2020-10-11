class Solution
{
public:
    vector<int> bestCoordinate(vector<vector<int>> &towers, int radius)
    {
        vector<int> out;
        int maxSigQ = -1;
        for (int x = 0; x <= 50; x++)
        {
            for (int y = 0; y <= 50; y++)
            {

                int sigQ = 0;
                for (int i = 0; i < towers.size(); i++)
                {

                    int xx = towers[i][0], yy = towers[i][1], q = towers[i][2];
                    double dist = pow((xx - x) * (xx - x) + (yy - y) * (yy - y), 0.5);

                    if (dist <= radius)
                    {
                        sigQ += floor((q / (1 + dist)));
                    }
                }

                if (sigQ > maxSigQ)
                {
                    out = vector<int>{x, y};
                    maxSigQ = sigQ;
                }
            }
        }

        return out;
    }
};