/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
public:
    //vector<NestedInteger> nestedList;
    vector<int> flat;
    int iti, n;
    const int ERROR = 1000001;

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        //this->nestedList = nestedList;
        unroll(nestedList);
        iti = 0;
        n = flat.size();
    }

    void unroll(vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
            {
                flat.push_back(nestedList[i].getInteger());
            }
            else
            {
                unroll(nestedList[i].getList());
            }
        }
    }

    int next()
    {
        if (hasNext())
        {
            int temp = flat[iti];
            iti++;
            return temp;
        }

        return ERROR;
    }

    bool hasNext()
    {
        return iti < n;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */