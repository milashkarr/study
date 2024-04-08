#include "complex_number.hpp"

#include <gtest/gtest.h>

using MAst::Complex;

TEST(Ariphmetics, summ) {
	Complex a(7.0, 6.0);
	Complex b(2.0, 4.0);
	ASSERT_TRUE(a + b == Complex(9, 10));
}

TEST(Ariphmetics, substraction) {
	Complex a(7.0, 6.0);
	Complex b(2.0, 4.0);
	ASSERT_TRUE(a - b == Complex(5, 2));
}

TEST(Ariphmetics, multiply) {
	Complex a(7.0, 6.0);
	Complex b(2.0, 4.0);
	ASSERT_TRUE(a * b == Complex(-10, 40));
}

TEST(Ariphmetics, division) {
	Complex a(7.0, 6.0);
	Complex b(2.0, 4.0);
	ASSERT_TRUE(a / b == Complex(1.9, -0.8));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
