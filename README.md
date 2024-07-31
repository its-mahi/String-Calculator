# String Calculator

Welcome to the **String Calculator** project. This repository contains a C++ implementation of a string calculator, developed using **Test-Driven Development (TDD)**. It is designed to provide a robust utility for performing arithmetic operations on numbers provided in a string format.

## Overview

The String Calculator is designed to handle:

- **Basic Arithmetic**: Compute the total of integers provided in a string, using default delimiters like commas and newline characters.
- **Custom Delimiters**: Accommodate user-defined delimiters, whether they are single characters or sequences of characters.
- **Error Handling**: Identify negative numbers in the input and provide detailed error messages for better debugging.
- **Ignore Large Numbers**: Automatically disregard any numbers larger than 1000 when calculating the sum.
- **Call Count Tracking**: Track how many times the `Add()` method has been invoked.

## Getting Started

To get started with the String Calculator, follow these steps:

1. **Clone the Repository**:
   ```sh
   git clone https://github.com/its-mahi/String-Calculator.git
   ```

2. **Initialize and Update Submodules**:
   After cloning the repository, initialize and update the GoogleTest submodule:
   ```sh
   cd String-Calculator
   git submodule update --init --recursive
   ```

3. **Navigate to the Project Directory**:
   ```sh
   cd String-Calculator
   ```

4. **Build the Project**:
   Ensure that [CMake](https://cmake.org/) is installed, and then build the project using:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

5. **Run the Tests**:
   After building the project, you can execute the tests to verify functionality:
   ```sh
   make tests
   ctest
   ./StringCalculator
   ```

## Usage Example

Here is a basic example demonstrating how to use the String Calculator:

```cpp
#include "StringCalculator.h"

int main() {
    StringCalculator calculator;
    std::string input = "1,2,3";
    int result = calculator.add(input);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
```

In this example, the `add` method processes a string of numbers and returns their sum.

## Project Details

The String Calculator project is based on the **TDD Kata 1 - String Calculator** described by Roy Osherove. For more details, visit [Incubyte TDD Assessment](https://blog.incubyte.co/blog/tdd-assessment/) or [TDD Kata 1 - String Calculator](https://osherove.com/tdd-kata-1/).

1. **Basic Functionality**:
   - Implement the `Add` method to handle 0, 1, or 2 numbers, returning their sum. For an empty string, return 0.
   - Examples: `"" == 0`, `"1" == 1`, `"1,2" == 3`.

2. **Extended Functionality**:
   - Allow the `Add` method to handle an unknown number of numbers.
   - Support newline characters between numbers, e.g., `"1\n2,3" == 6`.
   - Support custom delimiters specified at the beginning of the string, e.g., `"//;\n1;2" == 3`.

3. **Error Handling**:
   - Throw an exception for negative numbers with a message listing all negative numbers.
   - Ignore numbers greater than 1000, e.g., `2 + 1001 == 2`.

4. **Advanced Features**:
   - Support delimiters of any length and multiple delimiters, e.g., `"//[***]\n1***2***3" == 6` or `"//[*][%]\n1*2%3" == 6`.

## Test Cases

1. **Empty String Should Return 0**  
   **Test**: `EmptyStringReturnsZero`  
   - Returns 0 for an empty string.  
   - Example: `""` -> `0`

2. **Single Number String Should Return That Number**  
   **Test**: `SingleNumberReturnsItself`  
   - Returns the number itself for a single number string.  
   - Examples: `"1"` -> `1`, `"24"` -> `24`

3. **Two Number String Should Return Sum of Two**  
   **Test**: `TwoNumbersReturnSum`  
   - Returns the sum of two numbers separated by a comma.  
   - Example: `"1,5"` -> `6`

4. **Multiple Numbers Return Sum**  
   **Test**: `HandlesMultipleNumbersReturnSum`  
   - Returns the sum of all numbers in the string.  
   - Example: `"1,2,3,4,5"` -> `15`

5. **Newline as Delimiter**  
   **Test**: `HandlesNewLineDelimiter`  
   - Handles `\n` as a delimiter.  
   - Examples: `"1\n2,3"` -> `6`, `"\n2\n2\n\n\n2\n"` -> `6`

6. **Custom Delimiter Handling**  
   **Test**: `HandlesCustomDelimiter`  
   - Handle string with custom delimiters and returns the sum of all numbers.
   - Examples: `"//;\n1;2"` -> `3`

7. **Exception for Negative Numbers**  
   **Test**: `ThrowsExceptionForNegativeNumber`  
   - Throws an exception for negative numbers, listing them.  
   - Example: `"-1,-2,3"` -> Exception with message "Negative numbers not allowed : -1, -2"

8. **Ignore Numbers > 1000**  
   **Test**: `NumbersGreaterThan1000`  
   - Ignores numbers greater than 1000.  
   - Example: `"2,1001"` -> `2`

9. **Multiple Delimiters**  
   **Test**: `MultipleCustomDelimiters`  
   - Supports multiple delimiters of any length.  
   - Examples: `"//[*][%]\n1*2%3"` -> `6`, `"//[***][%%%]\n10***20%%%30"` -> `60`

10. **Method Call Count**  
    **Tests**: `HandlesGetCalledCount`, `HandlesGetCalledCountAfterMultipleCalls`, `HandlesGetCalledCountNoCalls`  
    - Verifies the count of `add()` method calls.  
    - Examples: After `calc.add("1,2"); calc.add("3,4");` -> `calc.getCalledCount()` -> `2`

<hr/>


