#include "Sphere.h"
#include "Vector.h"
#include <gtest/gtest.h>
#include <iostream>

class Sphere_test : public testing::Test {
public:

	virtual void SetUp() {
	}

};

TEST_F(Sphere_test, testGetNearestIntersection)
{
	const Sphere sphere({0, 0, 0, 1}, 1, Material(Color(1, 1, 1), 1, 1, 1, 1));
	ASSERT_EQ(9.0, sphere.getNearestIntersection(Ray({0, 0, -10, 1}, {0, 0, 1, 0})));
	ASSERT_EQ(0.0, sphere.getNearestIntersection(Ray({0, 0, -10, 1}, {0, 0, -1, 0})));
	ASSERT_EQ(0.0, sphere.getNearestIntersection(Ray({-1, -1, -10, 1}, {0, 0, 1, 0})));
	ASSERT_EQ(0.0, sphere.getNearestIntersection(Ray({-1, 1, -10, 1}, {0, 0, 1, 0})));
	ASSERT_EQ(0.0, sphere.getNearestIntersection(Ray({1, -1, -10, 1}, {0, 0, 1, 0})));
	ASSERT_EQ(0.0, sphere.getNearestIntersection(Ray({1, 11, -10, 1}, {0, 0, 1, 0})));
}
