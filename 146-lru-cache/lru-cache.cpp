class LRUCache {

private:
    struct Node {
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
            prev = nullptr;
        }

    };
    
    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }
    

    int get(int key) {
        
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        remove(node);
        insertAtHead(node);

        return node->value;

    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];
            node->value = value;

            remove(node);
            insertAtHead(node);

        } else{

            if(mp.size() == capacity) {

                Node* lru = tail->prev;
                mp.erase(lru->key);
                remove(lru);
                delete lru;

            }

            Node* node = new Node(key, value);
            mp[key] = node;
            insertAtHead(node);

        }


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */