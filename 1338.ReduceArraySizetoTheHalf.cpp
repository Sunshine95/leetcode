class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {

        unordered_map<int, int> freq;
        priority_queue<int> pq;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
        }

        for (auto it : freq)
        {
            pq.push(it.second);
        }

        int sum = 0, count = 0;
        while (sum < n / 2)
        {
            sum += pq.top();
            count++;
            pq.pop();
        }

        return count;
    }
};