#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int cnt = 0;
    int min_max = 0;
    priority_queue<int> min_q;
    priority_queue<int> max_q;
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            int num = stoi(operations[i].substr(2));
            max_q.push(num);
            min_q.push(-num);
            cnt++;
        }
        else if (operations[i][0] == 'D') {
            string cmd = operations[i].substr(2);
            if (cnt > 0) {
                if (cmd == "1") {
                    if (!max_q.empty())
                        max_q.pop();
                    min_max++;
                }
                else if (cmd == "-1") {
                    if (!min_q.empty())
                        min_q.pop();
                    min_max--;
                }
                cnt--;
            }
        }
        if (cnt == 0) {
            while (!min_q.empty()) { min_q.pop(); }
            while (!max_q.empty()) { max_q.pop(); }
        }
    }
    if (cnt <= 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else if (cnt == 1) {
        if (min_max > 0) {
            answer.push_back(max_q.top());
            answer.push_back(max_q.top());
        }
        else {
            answer.push_back(-min_q.top());
            answer.push_back(-min_q.top());
        }
    }
    else {
        answer.push_back(max_q.top());
        answer.push_back(-min_q.top());
    }

    return answer;
}