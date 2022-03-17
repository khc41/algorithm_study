#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct edge {
    int node[2];
    int value;
    edge(int a, int b, int c) {
        this->node[0] = a;
        this->node[1] = b;
        value = c;
    }
    bool operator<(edge& a) {
        return this->value < a.value;
    }
};

vector<edge> e;
int parent[101];

int find_parent(int n) {
    if (parent[n] == n) return n;
    else return find_parent(parent[n]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

bool find(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a == b) return false;
    else return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 0; i < costs.size(); i++)
        e.push_back(edge(costs[i][0], costs[i][1], costs[i][2]));
    sort(e.begin(), e.end());
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < e.size(); i++) {
        if (find(e[i].node[0], e[i].node[1])) {
            answer += e[i].value;
            union_parent(e[i].node[0], e[i].node[1]);
        }
    }

    return answer;
}