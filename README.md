# String Calculator

Welcome to the **String Calculator** project. This repository contains a C++ implementation of a string calculator, developed using **Test-Driven Development (TDD)**. It is designed to provide a robust utility for performing arithmetic operations on numbers provided in a string format.

## Overview

The String Calculator is designed to handle:

- **Basic Arithmetic**: Compute the total of integers provided in a string, using default delimiters like commas and newline characters.
- **Custom Delimiters**: Accommodate user-defined delimiters, whether they are single characters or sequences of characters.
- **Error Handling**: Identify negative numbers in the input and provide detailed error messages for better debugging.
- **Ignore Large Numbers**: Automatically disregard any numbers larger than 1000 when calculating the sum.

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

<hr/>
