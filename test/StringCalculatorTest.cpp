#include <gtest/gtest.h>
#include "StringCalculator.h"
using namespace std;


/*
    [ Test Case 1 ] : for empty string, result will be 0
*/
TEST(StringCalculatorTest, EmptyStringReturnsZero) {
    StringCalculator calc;
    ASSERT_EQ(calc.add(""), 0);
}

/*
    [ Test Case 2 ] : single number containing string will give number itself
*/
TEST(StringCalculatorTest, SingleNumberReturnsItself) {
    StringCalculator calc;
    EXPECT_EQ(calc.add("1"), 1);
    EXPECT_EQ(calc.add("24"), 24);
}

/*
    [ Test Case 3 ] : two number seperated by comman (,) will return sum of both number
*/
TEST(StringCalculatorTest, TwoNumbersReturnSum) {
    StringCalculator calc;
    EXPECT_EQ(calc.add("1,5"), 6);
}

/*
    [ Test Case 4 ] : multiple numbers seperated by comma (,) will return sum of all numbers
*/
TEST(StringCalculatorTest, HandlesMultipleNumbersReturnSum) {
    StringCalculator calc;
    EXPECT_EQ(calc.add("1,2,3,4,5"), 15);
}

/*
    [ Test Case 5 ] : string with "\n", add method will seperate numbers by "\n" (consider similar to delimiter)
*/
TEST(StringCalculatorTest, HandlesNewLineDelimiter) {
    StringCalculator calc;
    EXPECT_EQ(calc.add("1\n2,3"), 6);
}

/*
    [ Test Case 6 ] : string with custom delimiter and add method will seperate numbers by mentioned delimiter

    NOTE : delimiter can be of any length, it will be handled
*/
TEST(StringCalculatorTest, HandlesCustomDelimiter) {
    StringCalculator calc;

    EXPECT_EQ(calc.add("//;\n1;2"), 3);
    EXPECT_EQ(calc.add("//|\n1|2|3"), 6);
    EXPECT_EQ(calc.add("//:\n12:2\n1"), 15);
    EXPECT_EQ(calc.add("//:\n12:2:1"), 15);
    EXPECT_EQ(calc.add("//:\n12\n2:1"), 15);
    EXPECT_EQ(calc.add("//:\n12\n2\n1"), 15);
    EXPECT_EQ(calc.add("//:::\n12:::2\n1"), 15);

    EXPECT_EQ(calc.add("//:::\n122:::212\n112"), 446);
}

/*
    [ Test Case 7 ] : string with negative numbers, add method will throw an exception will message of all negative numbers
*/
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

    /*** 3 ***/
    try {
        calc.add("\n\n1,2,-3");
        FAIL() << "Expected runtime_error";
    } 
    catch (const runtime_error &err) {
        EXPECT_EQ(err.what(), string("Negative numbers not allowed : -3"));
    } 
    catch (...) {
        FAIL() << "Expected runtime_error";
    }
}


/*
    [ Test Case 8 ] : string with number with value of greater than 1000, add method will ignore it
*/
TEST(StringCalculatorTest, NumbersGreaterThan1000) {
    StringCalculator calc;
    EXPECT_EQ(calc.add("2,1001"), 2);
    EXPECT_EQ(calc.add("2,1000,5555,1001"), 1002);
    EXPECT_EQ(calc.add("1,999,1001,1002"), 1000);
}