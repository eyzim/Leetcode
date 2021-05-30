class MyHashSet {
private:
    unordered_set<int> mp;
public:
    MyHashSet() {
    }
    
    void add(int key) {
        mp.insert(key);
    }
    
    void remove(int key) {
        mp.erase(key);
    }
    
    bool contains(int key) {
        return mp.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */