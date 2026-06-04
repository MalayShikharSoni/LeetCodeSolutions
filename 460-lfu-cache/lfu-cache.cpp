class LFUCache {

private:
    struct Node {

        int key;
        int value;

        Node* next;
        Node* prev;

        int freq;

        Node(int k, int v) {

            key = k;
            value = v;
            next = nullptr;
            prev = nullptr;

            freq = 1;

        }

    };

    struct DLL {

        Node* head;
        Node* tail;

        int size;

        DLL() {

            head = new Node(0, 0);
            tail = new Node(0, 0);
        
            head->next = tail;
            tail->prev = head;

            size = 0;
        
        }

        void insert(Node* node) {

            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;

            size++;

        }

        void remove(Node* node) {

            node->next->prev = node->prev;
            node->prev->next = node->next;

            size--;

        }

        Node* removeLRU() {

            if(size == 0) {
                return nullptr;
            }

            Node* node = tail->prev;
            remove(node);

            return node;

        }

    };

    int capacity;
    int minFreq;
    unordered_map<int, Node*> keyMap;
    unordered_map<int, DLL*> freqMap;

public:

    LFUCache(int capacity) {
        
        this->capacity = capacity;
        minFreq = 0;

    }
    
    int get(int key) {
        
        if(keyMap.find(key) == keyMap.end()) {
            return -1;
        }

        Node* node = keyMap[key];
        updateFrequency(node);

        return node->value;

    }
    
    void put(int key, int value) {
        
        if(capacity == 0) {
            return;
        }

        if(keyMap.find(key) != keyMap.end()) {

            Node* node = keyMap[key];
            node->value = value;

            updateFrequency(node);

        } else {

            if(keyMap.size() == capacity) {

                DLL* list = freqMap[minFreq];
                Node* nodeToRemove = list->removeLRU();

                keyMap.erase(nodeToRemove->key);

                delete nodeToRemove;

            }

            Node* node = new Node(key, value);

            minFreq = 1;

            if(freqMap.find(1) == freqMap.end()) {

                freqMap[1] = new DLL();

            }

            freqMap[1]->insert(node);
            keyMap[key] = node;

        }

    }

    void updateFrequency(Node* node) {

        int oldFreq = node->freq;

        freqMap[oldFreq]->remove(node);

        if(oldFreq == minFreq && freqMap[oldFreq]->size == 0) {
            minFreq++;
        }

        node->freq++;

        if(freqMap.find(node->freq) == freqMap.end()) {
            freqMap[node->freq] = new DLL();
        }

        freqMap[node->freq]->insert(node);

    }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */