class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {

        int hash[26] = {0}, maxFreq = 0;
        int totalSlots = 0;

        for (char c : tasks)
        {
            hash[c - 'A']++;
            maxFreq = max(hash[c - 'A'], maxFreq);
        }

        totalSlots = (maxFreq - 1) * (n + 1);
        // for maxFreq-1 tasks, give n + 1 slots, and one more
        // for the terminal most frequent task added later.

        for (int i = 0; i < 26; i++)
        {
            if (hash[i] == maxFreq)
            {
                totalSlots++;
            }
            totalSlots -= hash[i];
        }

        return totalSlots > 0 ? tasks.size() + totalSlots : tasks.size();
    }
};