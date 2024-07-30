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

TEST(StringCalculatorTest, HandlesCustomDelimiter) {
    StringCalculator calc;

    EXPECT_EQ(calc.add("//;\n1;2"), 3);
    EXPECT_EQ(calc.add("//|\n1|2|3"), 6);
    EXPECT_EQ(calc.add("//:\n12:2\n1"), 15);
    EXPECT_EQ(calc.add("//:\n12:2:1"), 15);
    EXPECT_EQ(calc.add("//:\n12\n2:1"), 15);
    EXPECT_EQ(calc.add("//:\n12\n2\n1"), 15);
    EXPECT_EQ(calc.add("//:::\n12:::2\n1"), 15);
}

TEST(StringCalculatorTest, ThrowsExceptionForNegativeNumber) {
    StringCalculator calc;

    /*** 1 ***/
    try {
        calc.add("-1,-2,3");
        FAIL() << "Expected runtime_error";
    } 
    catch (const runtime_error &err) {
        EXPECT_EQ(err.what(), string("Negative numbers not allowed : -1, -2"));
    } 
    catch (...) {
        FAIL() << "Expected runtime_error";
    }


    /*** 2 ***/
    try {
        calc.add("1,2,-3");
        FAIL() << "Expected runtime_error";
    } 
    catch (const runtime_error &err) {
        EXPECT_EQ(err.what(), string("Negative numbers not allowed : -3"));
    } 
    catch (...) {
        FAIL() << "Expected runtime_error";
    }
}