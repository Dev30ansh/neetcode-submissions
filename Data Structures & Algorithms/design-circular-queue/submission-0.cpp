class MyCircularQueue {
   public:
    vector<int> que;
    int size;

    MyCircularQueue(int k) { size = k; }

    bool enQueue(int value) {
        if (que.size() == size) {
            return false;
        }
        else {
            que.push_back(value);
            return true;
        }
    }

    bool deQueue() {
        if(que.empty()){
            return false;
        }
        que.erase(que.begin());
        return true;
    }

    int Front() {
        if(que.empty()){
            return -1;
        }
        return que.front();
    }

    int Rear() {
        if(que.empty()){
            return -1;
        }
        return que.back();
    }

    bool isEmpty() {
        if(que.empty()){
            return true;
        }
        return false;
    }

    bool isFull() {
        if(que.size() == size){
            return true;
        }
        return false;
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