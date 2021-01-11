class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {

        unordered_map<int, int> freq;

        int width = 0, height = wall.size(), maxFreq = 0;
        width = accumulate(wall[0].begin(), wall[0].end(), width);

        for (int i = 0; i < height; i++)
        {
            int edge = 0;
            for (int j = 0; j < wall[i].size(); j++)
            {
                edge += wall[i][j];
                freq[edge]++;
                if (edge != width)
                {
                    maxFreq = max(maxFreq, freq[edge]);
                }
            }
        }

        return height - maxFreq;
    }
};