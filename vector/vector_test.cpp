#include "vector4.h"
#include <iostream>

using namespace vector;
using namespace std;

int main() {
	vector4 v(1, 2, 3, 4);
	vector4 w(1, 2, 3, 4);

	for (int i = 0; i < 1000 * 1000 * 100; i++) {
		vector4 u(v + w);
	}
}
