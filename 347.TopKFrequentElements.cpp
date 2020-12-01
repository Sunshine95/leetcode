class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> m;

        vector<int> set;

        for (int i : nums)
        {
            if (m.find(i) != m.end())
                m[i] += 1;
            else
                m[i] = 1;
        }

        for (auto i : m)
        {
            pq.push(make_pair(i.second, i.first));
        }

        for (int i = 0; i < k; i++)
        {
            set.push_back(pq.top().second);
            pq.pop();
        }

        return set;
    }
};