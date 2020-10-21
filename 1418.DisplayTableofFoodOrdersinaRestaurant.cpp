class Solution
{
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders)
    {

        int n = orders.size();

        unordered_map<int, unordered_map<string, int>> matrix;
        priority_queue<int, vector<int>, greater<int>> tables;
        priority_queue<string, vector<string>, greater<string>> foods;

        for (int i = 0; i < n; i++)
        {

            int t = stoi(orders[i][1]);
            string f = orders[i][2];

            tables.push(t);
            foods.push(f);
            matrix[t][f]++;
        }

        vector<vector<string>> out;
        out.push_back(vector<string>{"Table"});

        int col = 0;
        string f = "";
        while (!foods.empty())
        {
            if (foods.top() == f)
            {
                foods.pop();
                continue;
            }

            f = foods.top();
            out[0].push_back(f);
            foods.pop();

            col++;
        }

        int row = 1;
        int t = 0;
        while (!tables.empty())
        {
            if (t == tables.top())
            {
                tables.pop();
                continue;
            }

            t = tables.top();
            out.push_back(vector<string>{to_string(t)});
            for (int j = 1; j <= col; j++)
            {
                string f = out[0][j];
                out[row].push_back(to_string(matrix[t][f]));
            }
            row++;
            tables.pop();
        }

        return out;
    }
};