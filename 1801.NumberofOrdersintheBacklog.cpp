class Solution
{
public:
    int getNumberOfBacklogOrders(vector<vector<int>> &orders)
    {

        int MOD = 1000000007;
        int price = 0, amount = 1, type = 2;
        int buy = 0, sell = 1;

        priority_queue<int> buyLog;
        priority_queue<int, vector<int>, greater<int>> sellLog;
        unordered_map<int, int> buyHash;
        unordered_map<int, int> sellHash;

        for (int i = 0; i < orders.size(); i++)
        {

            if (orders[i][type] == buy)
            {

                while (!sellLog.empty() && sellLog.top() <= orders[i][price] && orders[i][amount] > 0)
                {

                    int SP = sellLog.top();

                    if (sellHash[SP] > orders[i][amount])
                    {
                        sellHash[SP] -= orders[i][amount];
                        orders[i][amount] = 0;
                    }
                    else
                    {
                        orders[i][amount] -= sellHash[SP];
                        sellHash[SP] = 0;
                        sellLog.pop();
                    }
                }

                if (orders[i][amount] > 0)
                {

                    if (buyHash.find(orders[i][price]) == buyHash.end() || buyHash[orders[i][price]] == 0)
                    {
                        buyLog.push(orders[i][price]);
                    }

                    buyHash[orders[i][price]] += orders[i][amount];
                }
            }
            else
            {

                while (!buyLog.empty() && buyLog.top() >= orders[i][price] && orders[i][amount] > 0)
                {

                    int BP = buyLog.top();

                    if (buyHash[BP] > orders[i][amount])
                    {
                        buyHash[BP] -= orders[i][amount];
                        orders[i][amount] = 0;
                    }
                    else
                    {
                        orders[i][amount] -= buyHash[BP];
                        buyHash[BP] = 0;
                        buyLog.pop();
                    }
                }

                if (orders[i][amount] > 0)
                {

                    if (sellHash.find(orders[i][price]) == sellHash.end() || sellHash[orders[i][price]] == 0)
                    {
                        sellLog.push(orders[i][price]);
                    }

                    sellHash[orders[i][price]] += orders[i][amount];
                }
            }
        }

        int out = 0, temp;
        while (!sellLog.empty())
        {
            temp = sellLog.top();
            out = (out + sellHash[temp]) % MOD;
            sellLog.pop();
        }
        while (!buyLog.empty())
        {
            temp = buyLog.top();
            out = (out + buyHash[temp]) % MOD;
            buyLog.pop();
        }

        return out;
    }
};