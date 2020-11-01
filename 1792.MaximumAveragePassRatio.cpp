class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {

        int n = classes.size();

        struct ComparePair
        {
            bool operator()(const pair<long double, int> &p1, const pair<double, int> &p2)
            {
                return p1.first < p2.first;
            }
        };

        priority_queue<pair<long double, int>, vector<pair<long double, int>>, ComparePair> pq;

        for (int i = 0; i < n; i++)
        {
            long double impact = (1.0 * (classes[i][0] + 1) / (classes[i][1] + 1)) - (1.0 * classes[i][0] / classes[i][1]);
            //cout << impact << " ";
            pq.push(make_pair(impact, i));
        }
        cout << "\n";

        for (int i = 0; i < extraStudents; i++)
        {
            auto p = pq.top();
            int j = p.second;
            //cout << j << "--\n";
            pq.pop();

            classes[j][0]++;
            classes[j][1]++;

            long double impact = (1.0 * (classes[j][0] + 1) / (classes[j][1] + 1)) - (1.0 * classes[j][0] / classes[j][1]);
            pq.push(make_pair(impact, j));
        }

        double count;
        for (int i = 0; i < n; i++)
        {
            count += (1.0 * classes[i][0] / classes[i][1]);
        }

        return 1.0 * count / n;
    }
};