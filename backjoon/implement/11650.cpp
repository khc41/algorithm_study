#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class point {
public:
    int x;
    int y;

    point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

bool compare(point& a, point& b) {
    if (a.x < b.x) {
        return true;
    }
    else if (a.x == b.x) {
        if (a.y < b.y)
            return true;
        else
            return false;
    }
    else return false;
}

int main() {
    int n, i, x, y;
    cin >> n;
    vector<point> in;
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        in.push_back(point(x, y));
    }
    sort(in.begin(), in.end(), compare);
    for (i = 0; i < n; i++) {
        printf("%d %d", in[i].x, in[i].y);
    }
}