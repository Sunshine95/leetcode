#include <bits/stdc++.h>
using namespace std;

int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{
    if (source == target)
        return 0;

    unordered_map<int, vector<int>> bus;

    for (int i = 0; i < routes.size(); i++)
    {
        for (int j = 0; j < routes[i].size(); j++)
        {
            int station = routes[i][j];
            bus[station].push_back(i);
        }
    }

    vector<bool> visited(routes.size(), false);

    unordered_set<int> targetBus;
    for (int i = 0; i < bus[target].size(); i++)
        targetBus.insert(bus[target][i]);

    queue<int> q;
    int count, step;
    bool found = false;

    for (int i = 0; i < bus[source].size(); i++)
    {
        int b = bus[source][i];
        q.push(b);
        visited[b] = true;
    }
    count = q.size(), step = 1;

    while (!q.empty())
    {

        int tempBus = q.front();
        q.pop();

        if (targetBus.find(tempBus) != targetBus.end())
        {
            found = true;
            break;
        }

        for (int i = 0; i < routes[tempBus].size(); i++)
        {
            int st = routes[tempBus][i];

            for (int j = 0; j < bus[st].size(); j++)
            {
                int adjBus = bus[st][j];

                if (!visited[adjBus])
                {
                    q.push(adjBus);
                    visited[adjBus] = true;
                }
            }
        }

        count--;
        if (count == 0)
        {
            step++;
            count = q.size();
        }
    }

    return found ? step : -1;
}

int main()
{

    int source, target;
    vector<vector<int>> routes;

    routes = {{1, 2, 7}, {3, 6, 7}};
    source = 1;
    target = 6;
    numBusesToDestination(routes, source, target);

    return 0;
}