#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, set<string>> alert;
    int mail[1001];
    for (int i = 0; i < 1001; i++) mail[i] = 0;
    for (int i = 0; i < report.size(); i++) {
        int index = report[i].find(" ");
        alert[report[i].substr(index + 1)].insert(report[i].substr(0, index));
    }
    for (int i = 0; i < id_list.size(); i++) {
        if (alert[id_list[i]].size() >= k) {
            for (auto it = alert[id_list[i]].begin(); it != alert[id_list[i]].end(); it++) {
                int index = find(id_list.begin(), id_list.end(), *it) - id_list.begin();
                mail[index]++;
            }
        }
    }
    for (int i = 0; i < id_list.size(); i++) {
        answer.push_back(mail[i]);
    }
    return answer;
}