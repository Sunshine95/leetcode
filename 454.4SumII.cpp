class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {

        unordered_map<int, int> h;
        int ans = 0;

        for (int a : A)
        {
            for (int b : B)
            {
                h[a + b]++;
            }
        }

        for (int c : C)
        {
            for (int d : D)
            {
                ans += h[-1 * (c + d)];
            }
        }

        return ans;
    }
};