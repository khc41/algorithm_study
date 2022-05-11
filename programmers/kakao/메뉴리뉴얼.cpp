#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
map<string, int> m;
void get_word(string str, string order, int idx, int course) {
    if (course == str.size()) {
        m[str]++;
        return;
    }
    if (idx == order.size()) return;
    get_word(str, order, idx + 1, course);
    get_word(str + order[idx], order, idx + 1, course);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < course.size(); i++) {
        for (int j = 0; j < orders.size(); j++) {
            sort(orders[j].begin(), orders[j].end());
            get_word("", orders[j], 0, course[i]);
        }
    }

    for (int i = 0; i < course.size(); i++) {
        vector<string> tmp;
        int max_order = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->first.size() == course[i] && it->second >= 2) {
                if (it->second > max_order) {
                    tmp.clear();
                    tmp.push_back(it->first);
                    max_order = it->second;
                }
                else if (it->second == max_order) {
                    tmp.push_back(it->first);
                }
            }
        }
        if (!tmp.empty()) for (int j = 0; j < tmp.size(); j++) answer.push_back(tmp[j]);
    }
    sort(answer.begin(), answer.end());

    return answer;
}