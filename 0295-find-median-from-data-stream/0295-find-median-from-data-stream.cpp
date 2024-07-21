class MedianFinder {
    int n;
    double median;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        
        if (!left.empty() && left.top() > num) {
            left.push(num);

            if (left.size() > right.size() + 1){
                right.push(left.top()); left.pop();
            }

        }
        else {
            right.push(num);
            if (right.size() > left.size() + 1){
                left.push(right.top()); right.pop();
            }
        }

        n++;        
    }
    
    double findMedian() {
        if (n & 1) {
            median = left.size() > right.size() ? left.top() : right.top();
        }
        else{
            median = left.top() + right.top();
            median /= 2;
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */