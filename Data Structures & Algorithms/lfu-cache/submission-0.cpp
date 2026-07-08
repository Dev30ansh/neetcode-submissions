class LFUCache {
public:
    //for its freq. count
    map<int, list<vector<int>>> freq;   //counter -> {key, value, counter}
    //for key and its address
    unordered_map<int, list<vector<int>>::iterator> mp;     //key -> address

    int cap;
    int size;

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    //helper function to mark it frequently used
    void makeFrequentlyUsed(int key){
        auto &vec = (*(mp[key]));

        int f = vec[2];
        int value = vec[1];

        //erase key from the list
        freq[f].erase(mp[key]);

        //if that couter is empty-> remove it from freq map
        if(freq[f].empty()){
            freq.erase(f);
        }
        //increse its counter and push in new counter of 'f'
        f++;
        freq[f].push_front(vector<int>({key,value, f}));

        //update address of key in the mp map
        mp[key] = freq[f].begin();

    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        auto &vec = (*(mp[key]));   // vec  = {key, value, counter}
       //access= { vec[0], vec[1], vec[2]}       
        int val = vec[1];

        //mark frequently used
        makeFrequentlyUsed(key);

        return val;
    }
    
    void put(int key, int value) {
        //check if already in mp list
        if(mp.find(key) != mp.end()){
            auto &vec = (*(mp[key]));

            vec[1] = value;
            //mark frequently used
            makeFrequentlyUsed(key);
        }
        else if(size < cap){
            //naya element aya-> add hote time freq. count 1 he hoga har element ka
            size++;
            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        }
        else{   //if size > capacity
            //remove the LFU (ka)-> LRU(if many elements in LFU)
            //LFU element freq map ke begin() me hoga i.e. freq->top joki ek list hai
            //and LRU vo list ka .back() element hoga(DISCUSSED IN LRU Cache question)

            auto &list_to_del_from = freq.begin()->second;
            int key_to_del = (list_to_del_from.back())[0];

            //remove from list
            list_to_del_from.pop_back();
            if(list_to_del_from.empty()){
                freq.erase(freq.begin()->first);
            }
            //remove from mp map
            mp.erase(key_to_del);

            //after making space push back element
            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */