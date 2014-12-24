#include "vector/vector4.h"
#include "sphere.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace vector;
using namespace shape;

int main() {
	sphere s(vector4(0, 0, 10, 1), 2.0);
	vector4 base(0, 0, 0, 1);

	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++) {
			scalar_t x = (i - 250) / 500.0;
			scalar_t y = (j - 250) / 500.0;
			vector4 dir = vector4(x, y, 1, 0);	
			dir = normalize(dir);
			
			scalar_t intersect = s.intersect(base, dir);
			cout << (intersect > 0.0);
//                        vector4 point = base + scale(dir, intersect);
//                        vector4 normal = s.get_normal(point);
		}
		cout << endl;
	}
}
