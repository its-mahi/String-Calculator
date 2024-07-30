#include "StringCalculator.h"
#include <string>
#include <stdexcept>

using namespace std;

//  [ add ] : uses various methods and returns the sum of all positive numbers.
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

// [ parseNumber ] : parse the given string and return the vector of all positive numbers.

vector<int> StringCalculator::parseNumbers(const string &numbers) {

    string processedNumbers = numbers;
    string delimiter = extractDelimiter(processedNumbers);

    return splitNumbers(processedNumbers, delimiter);
}

/* 
    [ extractDelimiter ] : extract delimiter from given string and return the value of delimiter, 
                           if custom delimiter is not given then by default it returns ",\n"
*/
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

/* 
    [ splitNumbers ] : returns vector of all positive numbers which is less than or equal to 1000
                       seperate all numbers with given delimiter from the given string
*/

vector<int> StringCalculator::splitNumbers(const string &numbers, const string &delimiter) {
    vector<int> result;
    vector<int> negativeNumbers;

    string currentNumber;
    string delimiters = delimiter + "\n";

    int pos = 0;

    while (pos < numbers.length()) {

        int delimiterPosition = numbers.length();

        for (int i=pos; i<numbers.length(); i++) {

            if (delimiters.find(numbers[i]) != string::npos) {

                delimiterPosition = i;
                break;
            }

        }
        
        string numberString = numbers.substr(pos, delimiterPosition - pos);
        

        // fetched next number and convert it into integer and push it into the vector
        if (numberString != "") {
            int num = stoi(numberString);

            if (num < 0) {
                negativeNumbers.push_back(num);
            }
            else if (num <= 1000) {
                result.push_back(num);
            }
        }
        
        pos = delimiterPosition + 1;
    }

    // if there is any negative numbers present, throw an exception with message of all negative numbers mentioned
    if (!negativeNumbers.empty()) {
        string errorMessage = "Negative numbers not allowed : ";

        for (int i = 0; i < negativeNumbers.size() ; i++) {
            errorMessage += to_string(negativeNumbers[i]);

            if (i < negativeNumbers.size() - 1) {
                errorMessage += ", ";
            }
        }

        throw runtime_error(errorMessage);
    }

    return result;
}