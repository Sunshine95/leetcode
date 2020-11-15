class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {

        int m = languages.size();
        vector<unordered_set<int>> speakers(n);
        unordered_set<int> unconnected;
        vector<int> count(n, 0);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < languages[i].size(); j++)
            {
                int lang = (--languages[i][j]);
                speakers[lang].insert(i);
            }
        }

        bool isConnected = false;
        for (int i = 0; i < friendships.size(); i++)
        {

            int u = (--friendships[i][0]);
            int v = (--friendships[i][1]);
            isConnected = false;

            for (int j = 0; j < languages[u].size(); j++)
            {
                int lang = languages[u][j];
                if (speakers[lang].find(v) != speakers[lang].end())
                {
                    isConnected = true;
                    break;
                }
            }

            if (isConnected)
            {
                continue;
            }
            else
            {
                unconnected.insert(u);
                unconnected.insert(v);
            }
        }

        for (int person : unconnected)
            for (int j = 0; j < languages[person].size(); j++)
                count[languages[person][j]]++;

        return unconnected.size() - *max_element(count.begin(), count.end());
    }
};