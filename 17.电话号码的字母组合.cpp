/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        go_through_string(digits, digits.begin());
        return result;
    }

    void go_through_string(const string& subdigits, string::iterator current) {
        if (current == subdigits.end()) {
            result.push_back(substring);
            return;
        }
        auto index = n_t_l -> pointTo.at(*current - '2');
        current++;

        for (auto& it: *index) {
            substring.push_back(it);
            go_through_string(subdigits, current);

            substring.pop_back();
        }
    }

private:
    struct numsToletter
    {
        vector<vector<char>*> pointTo;
        vector<char> num_a{'a', 'b', 'c'};
        vector<char> num_d{'d', 'e', 'f'};
        vector<char> num_g{'g', 'h', 'i'};
        vector<char> num_j{'j', 'k', 'l'};
        vector<char> num_m{'m', 'n', 'o'};
        vector<char> num_p{'p', 'q', 'r', 's'};
        vector<char> num_t{'t', 'u', 'v'};
        vector<char> num_w{'w', 'x', 'y', 'z'};

        numsToletter() {
            pointTo.push_back(&num_a);
            pointTo.push_back(&num_d);
            pointTo.push_back(&num_g);
            pointTo.push_back(&num_j);
            pointTo.push_back(&num_m);
            pointTo.push_back(&num_p);
            pointTo.push_back(&num_t);
            pointTo.push_back(&num_w);
        }
    };

    unique_ptr<numsToletter> n_t_l = make_unique<numsToletter>();
    string substring;
    vector<string> result;
};
// @lc code=end
