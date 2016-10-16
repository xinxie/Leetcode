class LRUCache{
private:
    typedef list<int> LIST;
    // first stores the value, second stores a iterator points to the key element in the list
    typedef pair<int, LIST::iterator> pr;
    typedef unordered_map<int, pr> map; // first stores the key

    int _capacity;
    LIST l; // stores all keys have been used
    map cache;

    void helper(map::iterator itr) {
        int key = itr->first;
        l.erase(itr->second.second);
        l.push_front(key);
        itr->second.second = l.begin();
    }

public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto itr = cache.find(key);
        if(itr == cache.end()) return -1;
        helper(itr);
        return itr->second.first;
    }

    void set(int key, int value) {
        auto itr = cache.find(key);
        if (itr != cache.end()) helper(itr);
        else {
            if(cache.size() == _capacity) {
                cache.erase(l.back());
                l.pop_back();
            }
            l.push_front(key);
        }
        cache[key] = make_pair(value, l.begin());
    }
};
