#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

bool check(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '-' || ch == '_' || ch == '.';
}

using namespace std;

string solution(string new_id) {
    string answer = "";
    stack<int> s;
    stack<int> e;
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    for (int i = 0; i < new_id.size(); i++) {
        int point = 0;
        if (!check(new_id[i])) {
            new_id.erase(i, 1);
            i--;
        }
    }
    bool point = false;
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '.') {
            if (!point) {
                point = true;
                s.push(i);
            }
        }
        else {
            if (point) {
                point = false;
                e.push(i - 1);
            }
        }
        if (i == new_id.size() - 1 && point) e.push(i);
    }
    while (!s.empty() && !e.empty()) {
        int start = s.top();
        int end = e.top();
        s.pop(); e.pop();
        if (start == end) continue;
        new_id.replace(start, end - start + 1, ".");
    }
    if (new_id[0] == '.') new_id.erase(0, 1);
    if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);
    if (new_id == "") new_id = "a";
    if (new_id.size() >= 16) {
        new_id = new_id.substr(0, 15);
    }
    if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);
    int size = new_id.size();
    if (size <= 2) {
        char last = new_id[size - 1];
        for (int i = 0; i < 3 - size; i++) {
            new_id += last;
        }
    }
    answer = new_id;
    return answer;
}