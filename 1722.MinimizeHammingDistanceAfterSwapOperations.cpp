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
        else
        {
            return find(parent[x]);
        }
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

    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        int n = source.size();
        parent.resize(n, -1);

        int temp;
        vector<unordered_map<int, int>> bucket(n);

        for (int i = 0; i < allowedSwaps.size(); i++)
        {
            uni(allowedSwaps[i][0], allowedSwaps[i][1]);
        }

        for (int i = 0; i < n; i++)
        {
            temp = find(i);

            if (bucket[temp].find(source[i]) == bucket[temp].end())
            {
                bucket[temp][source[i]] = 1;
            }
            else
            {
                bucket[temp][source[i]]++;
            }
        }

        int hDist = 0;
        for (int i = 0; i < n; i++)
        {
            temp = find(i);

            if (bucket[temp].find(target[i]) == bucket[temp].end())
            {
                hDist++;
            }
            else
            {
                if (bucket[temp][target[i]] <= 0)
                {
                    hDist++;
                }
                bucket[temp][target[i]]--;
            }
        }

        return hDist;
    }
};