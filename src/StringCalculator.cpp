#include "StringCalculator.h"
#include <string>
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

    string processedNumbers = numbers;
    string delimiter = extractDelimiter(processedNumbers);

    return splitNumbers(processedNumbers, delimiter);
}

string StringCalculator::extractDelimiter(string &numbers) {

    if (numbers.substr(0, 2) == "//") {
        int pos = numbers.find('\n');

        if (pos < 3) {
            throw invalid_argument("Invalid format for delimiter");
        }

        string delimiter = numbers.substr(2, pos - 2);
        numbers = numbers.substr(pos + 1);

        return delimiter;
    }

    return ",\n";       // default delimiter
}

vector<int> StringCalculator::splitNumbers(const string &numbers, const string &delimiter) {
    vector<int> result;
    string currentNumber;
    string delimiters = delimiter + "\n";

    int pos = 0;

    while (pos < numbers.length()) {

        int delPos = numbers.length();

        for (int i=pos; i<numbers.length(); i++) {

            if (delimiters.find(numbers[i]) != string::npos) {

                delPos = i;
                break;
            }

        }
        
        string numberPart = numbers.substr(pos, delPos - pos);
        
        if (numberPart != "") {
            result.push_back(stoi(numberPart));
        }
        
        pos = delPos + 1;
    }

    return result;
}