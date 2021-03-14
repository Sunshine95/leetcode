#include <bits/stdc++.h>
using namespace std;

int m, n;
void fillAdj(int num, vector<int>& adj)
{
    cout << "adj list for " << num << ": ";
    vector<int> binaryNum(m * n, 0);
    vector<int> temp(m*n);

    for(int i = 0; i < m*n; i++)
    {
        binaryNum[i] = (num & 1);
        num >>= 1;
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
            temp = binaryNum;

            temp[(i * n) + j] = 1 - temp[(i * n) + j];

            vector<int> rd = {0, 1, 0, -1};
            vector<int> cd = {1, 0, -1, 0};

            for (int k = 0; k < 4; k++)
            {

                int rr = i + rd[k];
                int cc = j + cd[k];

                if (rr >= m || cc >= n)
                    continue;
                if (rr < 0 || cc < 0)
                    continue;

                temp[(rr * n) + cc] = 1 - temp[(rr * n) + cc];
            }

            int decTemp = 0;
            for (int ii = 0; ii < temp.size(); ii++)
            {
                if (temp[ii] == 1)
                {
                    decTemp += (1 << ii);
                }
            }
            cout << decTemp << " ";
            adj.push_back(decTemp);
        }
    }
    cout << "\n";
}

int minFlips(vector<vector<int>> &mat)
{

    m = mat.size();
    n = mat[0].size();
    int v = 1 << (m * n);
    int step, count, target;
    bool found = false;

    target = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                target += (1 << ((i * n) + j));
            }
        }
    }
    cout << "target: " << target << "\n";

    vector<bool> visited(v, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    step = 0, count = 1;
    while (!q.empty())
    {
        vector<int> adj;

        int temp = q.front();
        q.pop();
        if (temp == target)
        {
            found = true;
            break;
        }

        fillAdj(temp, adj);

        for (int j : adj)
        {
            cout << "pushing.. ";
            if (!visited[j])
            {   
                cout << j << " ";
                q.push(j);
                visited[j] = true;
            }
        }
        cout << "\n";

        adj.clear();

        count--;
        if (count == 0)
        {
            step++;
            count = q.size();
            cout << "next step.." << count << "\n";
        }
    }

    return found ? step : -1;
}

int main()
{

    vector<vector<int>> mat;

    mat = {
        {0, 0},
        {0, 1}};
    cout << minFlips(mat) << endl << endl;
    
    mat = {
        {1, 0, 0},
        {1, 0, 0}
    };
    cout << minFlips(mat) << endl;

    return 0;
}