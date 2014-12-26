#include "shape/Sphere.h"
#include "vector/Vector.h"
#include <iostream>

int main() {
    shape::Sphere s(Vector4d(0, 0, 0, 0), 1); 
    Vector4d n = s.getNormal(Vector4d(1, 0, 0, 0));
    std::cout << n << std::endl;
}
