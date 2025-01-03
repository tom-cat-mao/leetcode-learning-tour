/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        mystack.push_back(val);
        if (minstack.empty() || val <= minstack.back()) {
            minstack.push_back(val);
        }
    }
    
    void pop() {
        if (mystack.back() == minstack.back()) {
            minstack.pop_back();
        }
        mystack.pop_back();
    }
    
    int top() {
        return mystack.back();
    }
    
    int getMin() {
        return minstack.back();
    }

private:
    vector<int> mystack;
    vector<int> minstack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

