class MyCircularQueue
{
public:
    int front, rear, k;
    vector<int> q;

    MyCircularQueue(int k)
    {
        q.resize(k, -1);
        front = 0, rear = 0;
        this->k = k;
    }

    bool enQueue(int value)
    {

        if (isFull())
        {
            return false;
        }

        q[rear % k] = value;
        rear++;

        return true;
    }

    bool deQueue()
    {

        if (isEmpty())
        {
            return false;
        }

        q[front % k] = -1;
        front++;

        return true;
    }

    int Front()
    {

        if (isEmpty())
        {
            return -1;
        }

        return q[front % k];
    }

    int Rear()
    {

        if (isEmpty())
        {
            return -1;
        }

        return q[(rear - 1) % k];
    }

    bool isEmpty()
    {
        return (rear - front == 0);
    }

    bool isFull()
    {
        return (rear - front == k);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */