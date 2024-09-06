#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <cstdlib>

class RandomizedSet {
public:
    std::unordered_map<int, int> mp; // map to store element and its index in the vector
    std::vector<int> nums;           // vector to store the elements
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false; // value already exists
        }
        // Insert the value in the vector and map
        nums.push_back(val);
        mp[val] = nums.size() - 1; // store the index in the map
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false; // value does not exist
        }
        // Move the last element to the position of the element to be removed
        int lastElement = nums.back();
        mp[lastElement] = mp[val];
        nums[mp[val]] = lastElement;
        
        // Remove the element
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        // Get a random index between 0 and nums.size()-1
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
