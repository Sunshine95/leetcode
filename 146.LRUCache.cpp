class LRUCache
{

    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    int cache_capacity;

public:
    LRUCache(int capacity)
    {
        cache_capacity = capacity;
    }

    int get(int key)
    {

        int value = -1;

        if (hash.find(key) != hash.end())
        {

            value = (*hash[key]).second;

            cache.erase(hash[key]);
            cache.push_front(pair<int, int>{key, value});

            hash[key] = cache.begin();
        }

        return value;
    }

    void put(int key, int value)
    {

        if (hash.find(key) == hash.end())
        {
            cache.push_front(pair<int, int>{key, value});
            hash[key] = cache.begin();
        }
        else
        {
            cache.erase(hash[key]);
            cache.push_front(pair<int, int>{key, value});
            hash[key] = cache.begin();
        }

        if (cache.size() > cache_capacity)
        {
            hash.erase(cache.back().first);
            cache.pop_back();
        }
    }
};