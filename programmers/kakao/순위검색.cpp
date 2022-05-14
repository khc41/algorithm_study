#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, map<string, map<string, map<string, vector<int>>>>> m;
    for (int i = 0; i < info.size(); i++) {
        string tmp = info[i];
        vector<string> s;
        for (int j = 0; j < 4; j++) {
            int idx = tmp.find(" ");
            s.push_back(tmp.substr(0, idx));
            tmp = tmp.substr(idx + 1);
        }
        int point = stoi(tmp);
        m[s[0]][s[1]][s[2]][s[3]].push_back(point);
    }
    for (int i = 0; i < query.size(); i++) {
        int human = 0;
        string tmp = query[i];
        vector<string> s;
        for (int j = 0; j < 4; j++) {
            int idx = tmp.find(" ");
            s.push_back(tmp.substr(0, idx));
            tmp = tmp.substr(idx + 5);
        }
        int point = stoi(tmp);

        for (int j = 0; j < m[s[0]][s[1]][s[2]][s[3]].size(); j++) {
            if (m[s[0]][s[1]][s[2]][s[3]][j] >= point) human++;
        }
        answer.push_back(human);
    }
    return answer;
}

