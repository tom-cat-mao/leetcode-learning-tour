/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    Trie() {
        root = make_shared<T_Node>(new T_Node());
    }

    void insert(string word) {
        shared_ptr<T_Node> ptr = root;

        for (const char& c: word) {
            if (ptr -> children.at(c - 'a') == nullptr) ptr -> children.at(c - 'a') = make_shared<T_Node>(new T_Node());
            else ptr = ptr -> children.at(c - 'a');
        }

        ptr -> isEnd = true;
    }

    bool search(string word) {
        return false;
    }

    bool startsWith(string prefix) {
        return false;
    }
private:
    struct T_Node {
        vector<shared_ptr<T_Node>> children;
        bool isEnd = false;

        T_Node() : children(26, nullptr) {}

    };

    shared_ptr<T_Node> root;
    int size;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
