class MyCircularDeque {
public:
    int capacity;
    deque<int> dq;
    
    MyCircularDeque(int k) {
        this->capacity = k;  
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        dq.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        dq.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if (!dq.empty()) {
            dq.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if (!dq.empty()) {
            dq.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if (!dq.empty()) {
            return dq.front();
        }
        return -1;
    }
    
    int getRear() {
        if (!dq.empty()) {
            return dq.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return dq.size() == capacity;
    }
};
