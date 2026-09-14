class LFUCache {
public:
    struct Node {
        int value;
        int freq;
        list<int>::iterator it;
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node> keyMap;
    unordered_map<int, list<int>> freqMap;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(int key) {
        Node& node = keyMap[key];
        int freq = node.freq;

        freqMap[freq].erase(node.it);

        if (freqMap[freq].empty() && minFreq == freq) {
            minFreq++;
        }

        node.freq++;

        freqMap[node.freq].push_back(key);
        node.it = prev(freqMap[node.freq].end());
    }

    int get(int key) {
        if (keyMap.find(key) == keyMap.end()) {
            return -1;
        }

        updateFreq(key);
        return keyMap[key].value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        if (keyMap.find(key) != keyMap.end()) {
            keyMap[key].value = value;
            updateFreq(key);
            return;
        }

        if (keyMap.size() == capacity) {
            int lruKey = freqMap[minFreq].front();
            freqMap[minFreq].pop_front();
            keyMap.erase(lruKey);
        }

        freqMap[1].push_back(key);

        Node node;
        node.value = value;
        node.freq = 1;
        node.it = prev(freqMap[1].end());

        keyMap[key] = node;
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */