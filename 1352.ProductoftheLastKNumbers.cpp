class ProductOfNumbers
{
public:
    ProductOfNumbers()
    {
        prefix.push_back(1);
    }

    void add(int num)
    {

        if (num != 0)
        {
            prefix.push_back(num * prefix.back());
        }
        else
        {
            prefix.clear();
            prefix.push_back(1);
        }

        return;
    }

    int getProduct(int k)
    {
        int n = prefix.size();
        int product;

        if (k < n)
        {
            product = prefix[n - 1] / prefix[n - k - 1];
        }
        else
        {
            return 0;
        }

        return product;
    }

private:
    vector<int> prefix;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */