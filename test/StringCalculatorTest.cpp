#include <gtest/gtest.h>
#include "StringCalculator.h"
using namespace std;

TEST(StringCalculatorTest, EmptyStringReturnsZero) {
    StringCalculator calc;
    ASSERT_EQ(calc.add(""), 0);
}
