#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <set>
using namespace std;

int get_time(int in_h, int in_m, int out_h, int out_m) {
    int ret_h = out_h - in_h;
    int ret_m = out_m - in_m;
    if (ret_m < 0) {
        ret_m += 60;
        ret_h--;
    }
    return ret_h * 60 + ret_m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    set<string> rest;
    map<string, int> total;
    string car[10000];
    for (int i = 0; i < records.size(); i++) {
        int car_num = stoi(records[i].substr(6, 4));
        if (records[i].substr(11) == "IN") {
            car[car_num] = records[i].substr(0, 2) + records[i].substr(3, 2);
            rest.insert(records[i].substr(6, 4));
        }
        else {
            int in_hour = stoi(car[car_num].substr(0, 2));
            int in_minute = stoi(car[car_num].substr(2, 2));
            int out_hour = stoi(records[i].substr(0, 2));
            int out_minute = stoi(records[i].substr(3, 2));
            total[records[i].substr(6, 4)] += get_time(in_hour, in_minute, out_hour, out_minute);
            car[car_num] = "";
        }
    }

    for (auto it = rest.begin(); it != rest.end(); it++) {
        if (car[stoi(*it)] != "") {
            total[*it] += get_time(stoi(car[stoi(*it)].substr(0, 2)),
                stoi(car[stoi(*it)].substr(2, 2)), 23, 59);
        }

        int total_time = total[*it];
        int bill = fees[1];
        if (total_time > fees[0]) {
            total_time -= fees[0];
            bill += (total_time / fees[2]) * fees[3];
            if (total_time % fees[2] != 0) bill += fees[3];
        }
        answer.push_back(bill);
    }

    return answer;
}