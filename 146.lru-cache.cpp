/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
private:
    // doubly linked list
    struct Node {
        int key;
        int value;
        Node *prev;
        Node *next;

        Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr);
    }

    int size = capacity;
    // the most use in the front, the least use in the tail
    unordered_map<int, Node*> cache;

    Node *head;
    Node *tail;

    void addToFront(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        head->next->prev = head;
    }

    void removeNode(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addToFront(node);
    }

    Node* removeTail() {
        removeNode(tail->prev);
        return tail->prev;
    }

public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        // add new node the cache
        Node* node = new Node(key, value);
        addToFront(node);
        cache[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

