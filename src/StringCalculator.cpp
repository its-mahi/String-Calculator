#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>

using namespace std;

int StringCalculator::add(const string &numbers) {
    
    if(numbers == "") {
        return 0;
    }

    vector<int> numElement = parseNumbers(numbers);
    int sum = 0;
    for (auto num : numElement) {
        sum += num;
    }
    
    return sum;
}

vector<int> StringCalculator::parseNumbers(const string &numbers) {
    vector<int> result;
    string currentNumber;
    
    for (char c : numbers) {
        if (c == ',' || c == '\n') {
            if (currentNumber != "") {
                result.push_back(stoi(currentNumber));
                currentNumber = "";
            }
        }
        else {
            currentNumber += c;
        }
    }
    
    if (currentNumber != "") {
        result.push_back(stoi(currentNumber));
    }
    
    return result;
}