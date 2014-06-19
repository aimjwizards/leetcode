class LRUCache{
public:
    struct CacheEntry{
        int key;
        int val;
        CacheEntry(int k, int v): key(k), val(v) {}
    };
    int n_capacity;
    unordered_map<int, list<CacheEntry>::iterator> table;
    list<CacheEntry> cache;

		// basic requirement
		// 1) based on the key, get the value and update the position on the list
		// 2) based on the cacheEntry from the cache line, you can find the key to delete
		//    the oldest datum.

    void MoveToFront(int key) {
        auto entry = *table[key];
        cache.erase(table[key]);
        cache.push_front(entry);
        table[key]=cache.begin();
    }

    LRUCache(int capacity) {
        n_capacity = capacity;
    }
    
    int get(int key) {
        if(table.find(key)==table.end()) return -1;
        MoveToFront(key);
        return table[key]->val;
    }
    void set(int key, int value) {
        if(get(key)!=-1) {
            table[key]->val = value; 
            return;
        }
        if(cache.size()>=n_capacity) {
            int r_key = cache.back().key;
            table.erase(r_key);
            cache.pop_back();
        }
        CacheEntry en(key, value);
        cache.push_front(en);
        table[key] = cache.begin();
    
    }
};
