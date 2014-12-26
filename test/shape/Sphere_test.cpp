#include "shape/Sphere.h"
#include "vector/Vector.h"
#include <gtest/gtest.h>

class Sphere_test : public testing::Test {
public:

	virtual void SetUp() {
	}

};

TEST_F(Sphere_test, testConstructor)
{
	shape::Sphere sphere({1, 2, 3, 4}, 5);
	auto normal = sphere.getNormal({1, 2, 3, 4});

}
