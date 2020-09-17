//1202. Smallest String With Swaps
class Solution
{
public:
    vector<int> parent;

    int find(int x)
    {

        if (parent[x] == -1)
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void uni(int x, int y)
    {

        int xp = find(x);
        int yp = find(y);

        if (xp != yp)
        {
            parent[yp] = xp;
        }

        return;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {

        int temp;

        int n = s.size();
        parent.resize(n, -1);

        for (int i = 0; i < pairs.size(); i++)
        {
            uni(pairs[i][0], pairs[i][1]);
        }

        vector<string> bucket(n, "");

        for (int i = 0; i < n; i++)
        {
            temp = find(i);
            bucket[temp] += s[i];
        }

        for (int i = 0; i < n; i++)
        {
            sort(bucket[i].begin(), bucket[i].end(), [](char a, char b) { return a > b; });
        }

        string t;
        for (int i = 0; i < n; i++)
        {
            temp = find(i);
            t += bucket[temp].back();
            bucket[temp].pop_back();
        }

        return t;
    }
};