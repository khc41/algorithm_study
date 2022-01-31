#include <iostream>
#include <cmath>
using namespace std;

int a[2], b[2], c[2], d[2];

typedef pair<double, double> POINT;

POINT minho(double p) {
	return { a[0] + (b[0] - a[0]) * (p / 100), a[1] + (b[1] - a[1]) * (p / 100) };
}

POINT kangho(double p) {
	return { c[0] + (d[0] - c[0]) * (p / 100), c[1] + (d[1] - c[1]) * (p / 100) };
}

int main() {	
	cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1] >> d[0] >> d[1];
	double lo = 0, hi = 100, p, q, ans = 2 * 10e4;
	while (hi - lo >= 1e-6) {
		p = (2 * lo + hi) / 3;
		q = (lo + 2 * hi) / 3;

		POINT m_p = minho(p);
		POINT m_q = minho(q);
		POINT k_p = kangho(p);
		POINT k_q = kangho(q);

		double p_len = sqrt(pow(m_p.first - k_p.first, 2) + pow(m_p.second - k_p.second, 2));
		double q_len = sqrt(pow(m_q.first - k_q.first, 2) + pow(m_q.second - k_q.second, 2));
		
		ans = min(ans, min(p_len, q_len));

		if (p_len >= q_len)
			lo = p;
		else
			hi = q;
	}
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << ans << "\n";
}