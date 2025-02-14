class ProductOfNumbers {
public:
    vector<int> prefix; // Stores cumulative product
    int lastZeroIndex;  // Stores the last zero index
    
    ProductOfNumbers() {
        prefix = {1};  // Initialize with 1 for easy multiplication
        lastZeroIndex = -1;
    }
    
    void add(int num) {
        if (num == 0) {
            // Reset everything after encountering 0
            prefix = {1};
            lastZeroIndex = prefix.size() - 1;
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        if (n - k - 1 < lastZeroIndex) return 0;  // If zero exists in the range
        
        return prefix[n - 1] / prefix[n - k - 1]; // Compute product using division
    }
};
