/*
460. LFU Cache
Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.
Follow up:
Could you do both operations in O(1) time complexity?
Example:
LFUCache cache = new LFUCache( 2 /* capacity */ );
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

From <https://leetcode.com/problems/lfu-cache/description/>
*/

class LFUCache {
public:
    int capacity;
    int size;
    int minFrequency;

    unordered_map<int,pair<int,int>> myMap; // {key, {value,frequency}}
    unordered_map<int,list<int>::iterator> myMapIterator; //{key,{list->iterators}}
    unordered_map<int,list<int>> frequency; //{frequency,{keylist}}

    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }

    int get(int key) {
        if(myMap.find(key) == myMap.end()) {
            return -1;
        }

        frequency[myMap[key].second].erase(myMapIterator[key]);
        myMap[key].second++;
        frequency[myMap[key].second].push_back(key);
        myMapIterator[key] = --frequency[myMap[key].second].end();

        if(frequency[minFrequency].size() == 0) {
            minFrequency++;
        }

        //returns the value
        return myMap[key].first;
    }

    void put(int key, int value) {
        if(capacity <= 0 ) {
            return;
        }

        int storedValue = get(key);

        //If the key is already present update the value and frequency updation is tkaen care under the get()
        if(storedValue != -1) {
            myMap[key].first = value;
            return;
        }

        if(size >= capacity) {
            myMap.erase(frequency[minFrequency].front());
            myMapIterator.erase(frequency[minFrequency].front());
            frequency[minFrequency].pop_front();
            size--;
        }

        myMap[key] = {value,1};
        frequency[1].push_back(key);
        myMapIterator[key] = --frequency[1].end();
        minFrequency = 1;
        size++;

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
