#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<vector<int>>> memo;

int dp(int c1, int c2, int r, vector<vector<int>> &grid)
{

    if (memo[r][c1][c2] != -1)
    {
        return memo[r][c1][c2];
    }

    int score = 0;
    if (r + 1 < m)
    {
        vector<int> next = {-1, 0, 1};
        for (int i = 0; i < 3; i++)
        {

            int cc1 = c1 + next[i];
            if (cc1 < 0 || cc1 >= n)
                continue;

            for (int j = 0; j < 3; j++)
            {

                int cc2 = c2 + next[j];
                if (cc2 < 0 || cc2 >= n)
                    continue;

                score = max(score, dp(cc1, cc2, r + 1, grid));
            }
        }
    }

    if (c1 == c2)
    {
        score += grid[r][c1];
    }
    else
    {
        score += (grid[r][c1] + grid[r][c2]);
    }

    return (memo[r][c1][c2] = score);
}

int cherryPickup(vector<vector<int>> &grid)
{
    m = grid.size();
    n = grid[0].size();

    memo.resize(m, vector<vector<int>>(n, vector<int>(n, -1)));
    return dp(0, n - 1, 0, grid);
}

int main()
{

    vector<vector<int>> grid;
    int cherr;

    grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}};
    cherr = cherryPickup(grid);
    cout << cherr << "\n";

    memo.clear();

    grid = {{8, 8, 10, 9, 1, 7}, {8, 8, 1, 8, 4, 7}, {8, 6, 10, 3, 7, 7}, {3, 0, 9, 3, 2, 7}, {6, 8, 9, 4, 2, 5}, {1, 1, 5, 8, 8, 1}, {5, 6, 5, 2, 9, 9}, {4, 4, 6, 2, 5, 4}, {4, 4, 5, 3, 1, 6}, {9, 2, 2, 1, 9, 3}};
    cherr = cherryPickup(grid);
    cout << cherr << "\n";
}