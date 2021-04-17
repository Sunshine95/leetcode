class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        unordered_map<int, int> lastRain;
        set<int> dryDay;
        vector<int> out(n);

        for (int i = 0; i < n; i++)
        {
            if (rains[i] > 0)
            {
                out[i] = -1;

                int lake = rains[i];
                if (lastRain.find(lake) == lastRain.end())
                {
                    lastRain[lake] = i;
                }
                else
                {
                    int j = lastRain[lake];
                    lastRain[lake] = i;
                    set<int>::iterator temp = dryDay.upper_bound(j);
                    if (temp != dryDay.end())
                    {
                        out[*temp] = lake;
                        dryDay.erase(temp);
                    }
                    else
                    {
                        return vector<int>();
                    }
                }
            }
            else
            {
                dryDay.insert(i);
            }
        }

        for (auto index : dryDay)
        {
            out[index] = 420;
        }

        // for(int i = 0 ; i < n ; i++){
        //     cout << out[i] << " ";
        // } cout << endl;

        return out;
    }
};