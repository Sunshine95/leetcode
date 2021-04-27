#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {

        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0, jump, i;

        for (i = 0; i < heights.size() - 1 && pq.size() < ladders; i++)
        {

            jump = heights[i + 1] - heights[i];

            if (jump > 0)
                pq.push(jump);
        }

        for (i; i < heights.size() - 1; i++)
        {

            jump = heights[i + 1] - heights[i];

            if (jump < 0)
                continue;

            if (!pq.empty() && jump > pq.top())
            {
                pq.push(jump);
                jump = pq.top();
                pq.pop();
            }

            if (bricks >= jump)
            {
                bricks -= jump;
            }
            else
            {
                break;
            }
        }

        return i;
    }
};