class Solution
{
public:
    int eatenApples(vector<int> &apples, vector<int> &days)
    {

        priority_queue<pair<int, int>> pq;
        int day = 0;
        int skip = 0;

        for (int i = 0; i < apples.size(); i++)
        {

            // add lables to pq
            pq.push(make_pair(-1 * (day + days[i]), i)); // -1 for min heap

            // throw out the rotten ones
            while (!pq.empty() && (-1 * pq.top().first) <= day)
            {
                pq.pop();
            }
            // throw out labels for eaten apples
            while (!pq.empty() && apples[pq.top().second] == 0)
            {
                pq.pop();
            }

            // try to eat
            if (pq.empty())
            {
                skip++;
            }
            else
            {
                apples[pq.top().second]--;
            } // eat

            day++;
        }

        // now draw down the stock
        while (!pq.empty())
        {

            while (!pq.empty() && (-1 * pq.top().first) <= day)
            {
                pq.pop();
            }
            while (!pq.empty() && apples[pq.top().second] == 0)
            {
                pq.pop();
            }

            if (pq.empty())
            {
                break;
            }
            else
            {
                apples[pq.top().second]--;
            } // eat

            day++;
        }

        return day - skip;
    }
};