class Solution
{
public:
    vector<bool> visited;

    bool dfs(vector<int> &out, int i, int n)
    {

        if (i == out.size())
            return true;

        if (out[i] > 0)
            return dfs(out, i + 1, n);

        for (int j = n; j > 0; j--)
        {

            if (visited[j])
                continue;

            if (j > 1 && (i + j >= out.size() || out[i + j] > 0))
                continue;

            out[i] = j;
            if (j > 1)
                out[i + j] = j;
            visited[j] = true;

            if (dfs(out, i + 1, n))
            {
                return true;
            }

            out[i] = 0;
            if (j > 1)
                out[i + j] = 0;
            visited[j] = false;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n)
    {

        vector<int> out((2 * n) - 1, 0);
        visited.resize(n + 1, false);
        dfs(out, 0, n);

        return out;
    }
};