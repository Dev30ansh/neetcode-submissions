class LRUCache {
public:
    vector<pair<int, int>>cache;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    //this will throw RUN TIME ERROR- TIME EXCEEDS-
    //because it if using erase func. inside a for loop 
    //  which increases the time for solving large capacity
    int get(int key) {

        for(int i = 0; i < cache.size(); i++){
            if(cache[i].first == key){
                //if found: 1) store its value
                int val = cache[i].second;
                
                //2) store its key and value
                pair<int, int> temp = cache[i];

                //3) move it to front as it is recentl used
                cache.erase(cache.begin() + i);
                cache.push_back(temp);
                
                return val;
            }
        }
        // else return -1
        return -1;
    }
    
    void put(int key, int value) {
        for(int i = 0; i < cache.size(); i++){
            // if already in the cache- update
            if(cache[i].first == key){
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }
        //not in cahce- insert it
        if(cache.size() == n){
            cache.erase(cache.begin()); //cache.begin() gives the address of front pair
            cache.push_back({key, value});
        }
        else{
            cache.push_back({key, value});
        }
    }
};
