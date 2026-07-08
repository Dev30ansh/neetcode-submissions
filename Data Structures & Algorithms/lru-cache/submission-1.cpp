class LRUCache {
public:
    list<int> dll;
//      cache    <key,     <Address of key   , value>>
    unordered_map<int, pair<list<int>::iterator, int>> cache;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }

    
    //func. to move recently used to front and not used to stay at back
    //1. erase the key using its address in the dll to reduce time taking
    //2. move key to front of dll
    //3. update address for that key in map

    void makeRecentlyUsed(int key){
        //cache[key].first - Address of key
        dll.erase(cache[key].first);        //1
        dll.push_front(key);                //2
        cache[key].first = dll.begin();   //3
    }

    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        //mark recently used;
        makeRecentlyUsed(key);

        return cache[key].second;
    }
    
    void put(int key, int value) {
        //key already in cache
        if(cache.find(key) != cache.end()){
            cache[key].second = value;
            makeRecentlyUsed(key);
        }
        else{   //not present in cache
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            n--;
        }

        //if acache size incereases than capacity
        if(n < 0){
            //delete from back of dll and also delete from map
            int key_to_delete = dll.back();
            cache.erase(key_to_delete);
            dll.pop_back();
            n++;
        }

    }
};
