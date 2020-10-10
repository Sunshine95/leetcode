class Solution
{
public:
    int countVowelStrings(int n)
    {

        // let word start with vowel V and be of length n;
        // then count(V, n) = SUM(count(v <= V, n-1));
        // count(v, 1) = 1;

        vector<int> count(5);
        count[0] = 1, count[1] = 2, count[2] = 3, count[3] = 4, count[4] = 5;

        for (int size = 2; size <= n; size++)
        {
            for (int v = 1; v <= 4; v++)
            {
                count[v] = count[v - 1] + count[v];
            }
        }

        return count[4];
    }
};