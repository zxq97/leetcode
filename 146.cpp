class LRUCache {
public:
    LRUCache(int capacity) {
        l.clear();
        m.clear();
        size = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())return -1;
        int value = m[key]->second;
        pair<int, int> p(key, value);
        list<pair<int, int>>::iterator del = m[key];
        l.erase(del);
        l.push_front(p);
        m[key] = l.begin();
        return value;
    }
    
    void put(int key, int value) {
        pair<int, int> p(key, value);
        if(m.find(key) == m.end()){
            if(size < capacity){
                l.push_front(p);
                ++size;
            }
            else{
                int del = l.rbegin()->first;
                m.erase(del);
                l.pop_back();
                l.push_front(p);
            }
        }
        else{
            list<pair<int, int>>::iterator del = m[key];
            l.erase(del);
            l.push_front(p);
        }
        m[key] = l.begin();
    }
    
private:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int size;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
