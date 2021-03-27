class Solution
{
public:
    vector<int> memo;
    int calc(int j, int d, vector<int> &arr)
    {

        if (memo[j] != 0)
            return memo[j];

        int vc = 1, i, m;
        int n = arr.size();

        i = j - 1;
        m = max(0, j - d);
        for (; i >= m; i--)
        {
            if (arr[i] < arr[j])
            {
                vc = max(vc, 1 + calc(i, d, arr));
            }
            else
            {
                break;
            }
        }

        i = j + 1;
        m = min(n - 1, j + d);
        for (; i <= m; i++)
        {
            if (arr[i] < arr[j])
            {
                vc = max(vc, 1 + calc(i, d, arr));
            }
            else
            {
                break;
            }
        }
        return (memo[j] = vc);
    }

    int maxJumps(vector<int> &arr, int d)
    {

        int n = arr.size();
        memo.resize(n, 0);

        int out = 0;
        for (int i = 0; i < n; i++)
        {
            out = max(out, calc(i, d, arr));
        }

        return out;
    }
};