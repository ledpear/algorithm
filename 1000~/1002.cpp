#include <iostream>
#include <cmath>
using namespace std;
int main() {
	
	double x1,y1, r1,x2,y2,r2;
	double result;
	double xx,rr1,rr2,rr3;

	int i;
	cin >> i;
	if (i > 0) {
		for (int j = 0; j < i; j++) {
			cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

			xx = std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
			rr2 = std::abs(r1 - r2);
			rr3 = r1 + r2;

			if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
				result = -1;
			}
			else if ((x1 == x2) && (y1 == y2) && (r1 != r2)) {
				result = 0;
			}
			else if (rr3>xx&&rr2<xx) {
				result = 2;
			}
			else if (rr3 == xx||rr2==xx) {
				result = 1;
			}
			else if (rr3<xx||rr2>xx) {
				result = 0;
			}

			cout << result << "\n";
		}
	}
	return 0;
}