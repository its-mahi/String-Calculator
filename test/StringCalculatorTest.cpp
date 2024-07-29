#include <gtest/gtest.h>
#include "StringCalculator.h"
using namespace std;

TEST(StringCalculatorTest, EmptyStringReturnsZero) {
    StringCalculator calc;
    ASSERT_EQ(calc.add(""), 0);
}

TEST(StringCalculatorTest, SingleNumberReturnsItself) {
    StringCalculator calc;
    EXPECT_EQ(calc.add("1"), 1);
}

TEST(StringCalculatorTest, TwoNumbersReturnSum) {
    StringCalculator calc;
    EXPECT_EQ(calc.add("1,5"), 6);
}

TEST(StringCalculatorTest, HandlesMultipleNumbersReturnSum) {
    StringCalculator calc;
    EXPECT_EQ(calc.add("1,2,3,4,5"), 15);
}

TEST(StringCalculatorTest, HandlesNewLineDelimiter) {
    StringCalculator calc;
    EXPECT_EQ(calc.add("1\n2,3"), 6);
}