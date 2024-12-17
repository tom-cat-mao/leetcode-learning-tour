/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:
    int capacity;
    unordered_map<int, int> Cache;
    vector<int> pointTo;

    LRUCache(int capacity) {
        this -> capacity = capacity;
    }

    int get(int key) {
        auto it = Cache.find(key);
        int result;

        if (it != Cache.end()) {
            result = it -> second;
            toback(key);
        } else result = -1;


        return result;
    }

    void put(int key, int value) {
        auto it = Cache.find(key);
        if (it != Cache.end()) {
            it -> second = value;
            toback(key);
            return;
        }

        if (pointTo.size() == capacity) {
            Cache.erase(*pointTo.begin());
            pointTo.erase(pointTo.begin());
        }

        pointTo.push_back(key);
        Cache.insert(make_pair(key, value));
    }

    void toback(int key) {
        auto it = find(pointTo.begin(), pointTo.end(), key);
        pointTo.erase(it);
        pointTo.push_back(key);
    }
};

// int main () {
//     LRUCache s(2);
//     s.put(1, 1);
//     s.put(2, 2);
//     cout << s.get(1) << endl;
//     s.put(3, 3);
//     cout << s.get(2) << endl;
//     s.put(4, 4);
//     cout << s.get(1) << endl;
//     cout << s.get(3) << endl;
//     cout << s.get(4) << endl;

//     return 0;
// }

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=en
